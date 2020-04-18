#include "character.hpp"

eztp::character::character::character(const std::string &initname, const std::string &initclass,
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

bool eztp::character::character::operator==(const character &a) const {
    return uid == a.uid;
}

bool eztp::character::character::operator==(const character &a) {
    return uid == a.uid;
}

eztp::character::character &eztp::character::character::operator=(const character &a) {
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
    effects = a.effects;

    uid = a.uid;

    return *this;
}

eztp::character::character &eztp::character::character::operator>>(const character &a) {
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

void eztp::character::character::refreshMods() {
    /**
     * Refresh the ability modifiers
     */

    for (std::pair<std::string, std::array<int, 2> > element : abilities) {
        abilities[element.first][1] = static_cast<int>((std::floor(element.second[0] / 2) - 5));
    }
}

void eztp::character::character::refreshAC() {
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

void eztp::character::character::addTrait(const std::string &name, const std::string &description) {
    traits.emplace(name, description);
}

void eztp::character::character::delTrait(const std::string &name) {
    traits.erase(name);
}

void eztp::character::character::addProf(const std::string &name) {
    proficiencies.push_back(name);
}

void eztp::character::character::delProf(const std::string &name) {
    proficiencies.erase(remove(proficiencies.begin(), proficiencies.end(), name), proficiencies.end());
}

void eztp::character::character::addItem(const std::string &name) {
    misc.push_back(name);
}

void eztp::character::character::delItem(const std::string &name) {
    misc.erase(remove(misc.begin(), misc.end(), name), misc.end());
}

void eztp::character::character::addCondition(const std::string &name) {
    conditions.push_back(name);
}

void eztp::character::character::delCondition(const std::string &name) {
    conditions.erase(remove(conditions.begin(), conditions.end(), name), conditions.end());
}

void eztp::character::character::setWeapon(const std::string &inWeapon) {
    equipment[0] = inWeapon;
}

void eztp::character::character::setArmor(const std::string &inArmor) {
    refreshAC();

    equipment[1] = inArmor;
}

std::string eztp::character::character::getWeapon() {
    /**
     * Gets the weapon name
     *
     * @return The weapon name
     */

    return equipment[0];
}

std::string eztp::character::character::getArmor() {
    /**
     * Gets the armor name
     *
     * @return The armor name
     */

    return equipment[1];
}

int eztp::character::character::attack(bool mod) {
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

void eztp::character::character::damage(int dmg) {
    hp -= dmg;
}

void eztp::character::character::heal(int heal) {
    hp += heal;
}

int eztp::character::character::rollSkill(const std::string &skill) {
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

void eztp::character::character::setRace(const std::string &name) {
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

void eztp::character::character::setBG(const std::string &name) {
    background::Background x = background::bgs[name];

    gp = x.gp;

    proficiencies.insert(proficiencies.end(), x.prof.begin(), x.prof.end());
    misc.insert(misc.end(), x.equip.begin(), x.equip.end());
}