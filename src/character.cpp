/*
 *  Copyright (C) 2020  Gabriele A. Ron
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "libeztp/character.hpp"

eztp::character::character(const std::string &initname, const std::string &initclass,
                                      const std::string &initrace,
                                      const std::string &initbg, int level, int strength, int dexterity,
                                      int constitution,
                                      int intelligence, int wisdom, int charisma, bool isNPC, unsigned long id) {
    /**
     * Creates the character with basic attributes and stats in an easy constructor
     *
     * Very basic and does not include equipment or spells, nor does it return anything
     *
     * @param initname The name of the character
     * @param initclass The class of the character
     * @param initrace The race of the character
     * @param initbg The background of the character
     *
     * @param level The character level
     *
     * @param strength The character's strength (Default 10)
     * @param dexterity The character's dexterity (Defult 10)
     * @param constitution The character's constitution (Default 10)
     * @param intelligence The character's intelligence (Default 10)
     * @param wisdom The character's wisdom (Default 10)
     * @param charisma The character's charisma (Default 10)
     *
     * @param isNPC Demarcates whether this is an NPC or PC
     */

    uid = id;

    cname = initname;
    crace = initrace;
    cclass = initclass;
    cbg = initbg;
    clevel = level;
    npc = isNPC;

    abilities = {{"STR", {strength,     static_cast<int>((std::floor(strength / 2) - 5))}},
                 {"DEX", {dexterity,    static_cast<int>((std::floor(dexterity / 2) - 5))}},
                 {"CON", {constitution, static_cast<int>((std::floor(constitution / 2) - 5))}},
                 {"INT", {intelligence, static_cast<int>((std::floor(intelligence / 2) - 5))}},
                 {"WIS", {wisdom,       static_cast<int>((std::floor(wisdom / 2) - 5))}},
                 {"CHA", {charisma,     static_cast<int>(std::floor(charisma / 2) - 5)}}};

    if (uid) {
        setRace(crace);
        setBG(cbg);
    }
}

bool eztp::character::operator==(const character &a) const {
    return uid == a.uid;
}

bool eztp::character::operator==(const character &a) {
    return uid == a.uid;
}

eztp::character &eztp::character::operator=(const character &a) {
    /**
     * Overriding the assignment operator to copy characters completely
     *
     * @param a The input character
     *
     * @return The copied character
     */

    npc = a.npc;

    cname = a.cname;
    crace = a.crace;
    cclass = a.cclass;
    cbg = a.cbg;
    clevel = a.clevel;

    abilities = a.abilities;

    hp = a.hp;
    maxHP = a.maxHP;
    ac = a.ac;
    gp = a.gp;
    speed = a.speed;

    equipment = a.equipment;
    misc = a.misc;
    proBonus = a.proBonus;
    proficiencies = a.proficiencies;
    traits = a.traits;
    saves = a.saves;
    languages = a.languages;

    size = a.size;

    vulnerabilities = a.vulnerabilities;
    resistances = a.resistances;
    immunities = a.immunities;
    conditions = a.conditions;

    uid = a.uid;

    return *this;
}

eztp::character &eztp::character::operator>>(const character &a) {
    /**
     * Overriding the right shift operator to soft copy characters
     *
     * Essentially copies equipment; That's all
     *
     * @param a The input character
     *
     * @return The soft copy of the character
     */

    gp = a.gp;

    equipment = a.equipment;
    misc = a.misc;

    return *this;
}

void eztp::character::refreshMods() {
    /**
     * Refresh the ability modifiers
     */

    for (std::pair<std::string, std::array<int, 2> > element : abilities) {
        abilities[element.first][1] = static_cast<int>((std::floor(element.second[0] / 2) - 5));
    }
}

void eztp::character::refreshAC() {
    /**
     * Refreshes the ac
     *
     * Required if a shield is added or removed
     */

    armor::Armor arm = armor::armors[equipment[1]];

    ac = arm.baseAC;

    if (abilities["DEX"][1] >= arm.dexMax) {
        ac += arm.dexMax;
    } else {
        ac += abilities["DEX"][1];
    }

    if (std::count(equipment.begin(), equipment.end(), "SHIELD")) {
        ac += 2;
    }
}

void eztp::character::addTrait(const std::string &name, const std::string &description) {
    traits.emplace(name, description);
}

void eztp::character::delTrait(const std::string &name) {
    traits.erase(name);
}

void eztp::character::addProf(const std::string &name) {
    proficiencies.push_back(name);
}

void eztp::character::delProf(const std::string &name) {
    proficiencies.erase(remove(proficiencies.begin(), proficiencies.end(), name), proficiencies.end());
}

void eztp::character::addItem(const std::string &name) {
    misc.push_back(name);
}

void eztp::character::delItem(const std::string &name) {
    misc.erase(remove(misc.begin(), misc.end(), name), misc.end());
}

void eztp::character::addCondition(const std::string &name) {
    conditions.push_back(name);
}

void eztp::character::delCondition(const std::string &name) {
    conditions.erase(remove(conditions.begin(), conditions.end(), name), conditions.end());
}

void eztp::character::setWeapon(const std::string &inWeapon) {
    equipment[0] = inWeapon;
}

void eztp::character::setArmor(const std::string &inArmor) {
    refreshAC();

    equipment[1] = inArmor;
}

std::string eztp::character::getWeapon() {
    /**
     * Gets the weapon name
     *
     * @return The weapon name
     */

    return equipment[0];
}

std::string eztp::character::getArmor() {
    /**
     * Gets the armor name
     *
     * @return The armor name
     */

    return equipment[1];
}

int eztp::character::attack(bool mod) {
    /**
     * Used to get the damage from a weapon attack
     *
     * @param mod Whether to add the ability modifier or not; default true
     *
     * @return the damage
     */

    weapons::Weapons weap = weapons::weaps[equipment[0]];

    int att = weap.ability;
    int abi = (att == 1) ? abilities["DEX"][1] : (att == 2) ? abilities["STR"][1] : (att == 3) ? (abilities["DEX"][1] >=
                                                                                                  abilities["STR"][1])
                                                                                                 ? abilities["DEX"][1]
                                                                                                 : abilities["STR"][1]
                                                                                               : 0;

    int dmg;

    mod ? dmg = abi : dmg = 0;

    for (int i = 0; i < weap.numberDice; ++i) {
        dmg += weap.die.roll();
    }

    return dmg;
}

void eztp::character::damage(int dmg) {
    hp -= dmg;
}

void eztp::character::heal(int heal) {
    hp += heal;
}

int eztp::character::rollSkill(const std::string &skill) {
    /**
     * Returns a random dice roll for the provided skill
     *
     * @param skill The skill to roll for
     *
     * @return The roll with skill & proficiency if applicable
     */

    int x = abilities[skills[skill]][1];

    if (std::count(proficiencies.begin(), proficiencies.end(), skill)) {
        x += proBonus;
    }

    return d20.roll() + x;
}

int eztp::character::save(const std::string &file) {
    std::ofstream out;
    out.open(file);

    if (out.good()) {
        out << npc << '\n';
        out << cname << '\n' << cclass << '\n' << crace << '\n' << cbg << '\n' << clevel << '\n';

        out << abilities["STR"][0] << "," << abilities["STR"][1] << '\n';
        out << abilities["DEX"][0] << "," << abilities["DEX"][1] << '\n';
        out << abilities["CON"][0] << "," << abilities["CON"][1] << '\n';
        out << abilities["WIS"][0] << "," << abilities["WIS"][1] << '\n';
        out << abilities["INT"][0] << "," << abilities["INT"][1] << '\n';
        out << abilities["CHA"][0] << "," << abilities["CHA"][1] << '\n';

        out << hp << "\n" << maxHP << "\n" << ac << "\n" << gp << "\n" << speed << "\n";

        if (!equipment.empty()) {
            for (int i = 0; i < equipment.size(); ++i) {
                out << equipment[i];

                if (i == equipment.size() - 1) {
                    out << "\n";
                } else {
                    out << ",";
                }
            }
        } else {
            out << "\n";
        }

        if (!misc.empty()) {
            for (int i = 0; i < misc.size(); ++i) {
                out << misc[i];

                if (i == misc.size() - 1) {
                    out << "\n";
                } else {
                    out << ",";
                }
            }
        } else {
            out << "\n";
        }

        out << proBonus << "\n";

        if (!proficiencies.empty()) {
            for (int i = 0; i < proficiencies.size(); ++i) {
                out << proficiencies[i];

                if (i == proficiencies.size() - 1) {
                    out << "\n";
                } else {
                    out << ",";
                }
            }
        } else {
            out << "\n";
        }

        if (!languages.empty()) {
            for (int i = 0; i < languages.size(); ++i) {
                out << languages[i];

                if (i == languages.size() - 1) {
                    out << "\n";
                } else {
                    out << ",";
                }
            }
        } else {
            out << "\n";
        }

        if (!saves.empty()) {
            for (int i = 0; i < saves.size(); ++i) {
                out << saves[i];

                if (i == saves.size() - 1) {
                    out << "\n";
                } else {
                    out << ",";
                }
            }
        } else {
            out << "\n";
        }

        out << size << "\n";

        if (!vulnerabilities.empty()) {
            for (int i = 0; i < vulnerabilities.size(); ++i) {
                out << vulnerabilities[i];

                if (i == vulnerabilities.size() - 1) {
                    out << "\n";
                } else {
                    out << ",";
                }
            }
        } else {
            out << "\n";
        }

        if (!resistances.empty()) {
            for (int i = 0; i < resistances.size(); ++i) {
                out << resistances[i];

                if (i == resistances.size() - 1) {
                    out << "\n";
                } else {
                    out << ",";
                }
            }
        } else {
            out << "\n";
        }

        if (!immunities.empty()) {
            for (int i = 0; i < immunities.size(); ++i) {
                out << immunities[i];

                if (i == immunities.size() - 1) {
                    out << "\n";
                } else {
                    out << ",";
                }
            }
        } else {
            out << "\n";
        }

        if (!conditions.empty()) {
            for (int i = 0; i < conditions.size(); ++i) {
                out << conditions[i];

                if (i == conditions.size() - 1) {
                    out << std::endl;
                } else {
                    out << ",";
                }
            }
        } else {
            out << "\n";
        }

        out << uid;

        out.flush();
        out.close();

        std::cout << "WRITTEN" << std::endl;
        return 1;
    } else {
        out.flush();
        out.close();

        std::cerr << "CAN'T WRITE" << std::endl;
        return 0;
    }
}

int eztp::character::load(const std::string &file) {
    std::ifstream fin;
    fin.open(file);

    if (fin.good()) {
        std::string tmp;
        std::string token;
        std::string delim = ",";
        size_t pos = 0;

        getline(fin, tmp);
        std::stoi(tmp) >> npc;
        getline(fin, cname);
        getline(fin, cclass);
        getline(fin, crace);
        getline(fin, cbg);
        getline(fin, tmp);
        std::stoi(tmp) >> clevel;

        for (auto &i : abilities) {
            getline(fin, tmp);
            token = tmp.substr(0, tmp.find(delim));
            abilities[i.first][0] = std::stoi(token);
            tmp.erase(0, tmp.find(delim) + delim.length());
            abilities[i.first][1] = std::stoi(tmp);
        }

        getline(fin, tmp);
        std::stoi(tmp) >> hp;
        getline(fin, tmp);
        std::stoi(tmp) >> maxHP;
        getline(fin, tmp);
        std::stoi(tmp) >> ac;
        getline(fin, tmp);
        std::stoi(tmp) >> gp;
        getline(fin, tmp);
        std::stoi(tmp) >> speed;

        tmp.clear();
        equipment.clear();
        getline(fin, tmp);
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            equipment.push_back(token);
            tmp.erase(0, pos + delim.length());
        }

        tmp.clear();
        misc.clear();
        getline(fin, tmp);
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            misc.push_back(token);
            tmp.erase(0, pos + delim.length());
        }

        getline(fin, tmp);
        std::stoi(tmp) >> proBonus;

        tmp.clear();
        proficiencies.clear();
        getline(fin, tmp);
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            proficiencies.push_back(token);
            tmp.erase(0, pos + delim.length());
        }

        tmp.clear();
        languages.clear();
        getline(fin, tmp);
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            languages.push_back(token);
            tmp.erase(0, pos + delim.length());
        }

        tmp.clear();
        saves.clear();
        getline(fin, tmp);
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            saves.push_back(token);
            tmp.erase(0, pos + delim.length());
        }

        getline(fin, tmp);
        tmp[0] >> size;

        tmp.clear();
        vulnerabilities.clear();
        getline(fin, tmp);
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            vulnerabilities.push_back(std::stoi(token));
            tmp.erase(0, pos + delim.length());
        }

        tmp.clear();
        resistances.clear();
        getline(fin, tmp);
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            resistances.push_back(std::stoi(token));
            tmp.erase(0, pos + delim.length());
        }

        tmp.clear();
        immunities.clear();
        getline(fin, tmp);
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            immunities.push_back(std::stoi(token));
            tmp.erase(0, pos + delim.length());
        }

        tmp.clear();
        conditions.clear();
        getline(fin, tmp);
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            conditions.push_back(token);
            tmp.erase(0, pos + delim.length());
        }

        getline(fin, tmp);
        std::stoi(tmp) >> uid;

        fin.close();

        std::cout << "READ" << std::endl;
        return 1;
    } else {
        fin.close();

        std::cerr << "CAN'T READ" << std::endl;
        return 0;
    }
}

void eztp::character::setRace(const std::string &name) {
    /**
     * Sets the race and abilities and stuff
     *
     * DO NOT RUN AFTER CONSTRUCTION
     */

    race::Race x = race::races[name];

    for (unsigned long i = 0; i < x.abis.size(); ++i) {
        if (x.abis[i] == "HP") {
            hp += x.boosts[i];
        } else {
            abilities[x.abis[i]][0] += x.boosts[i];
        }
    }

    refreshMods();

    size = x.size;
    speed = x.speed;

    traits.insert(x.traits.begin(), x.traits.end());
    proficiencies.insert(proficiencies.end(), x.prof.begin(), x.prof.end());
}

void eztp::character::setBG(const std::string &name) {
    background::Background x = background::bgs[name];

    gp = x.gp;

    proficiencies.insert(proficiencies.end(), x.prof.begin(), x.prof.end());
    misc.insert(misc.end(), x.equip.begin(), x.equip.end());
}