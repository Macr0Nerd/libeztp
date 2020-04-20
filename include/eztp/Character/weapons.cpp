#include "weapons.hpp"

using namespace eztp::character;

weapons::wmap weapons::weaps = {
        {"FISTS",          {"FISTS",          d1,  1, 1, 2,  false, 0, {0,   0}}},
        {"CLUB",           {"CLUB",           d4,  1, 1, 2,  false, 0, {0,   0}}},
        {"DAGGER",         {"DAGGER",         d4,  1, 3, 8,  false, 2, {20,  60}}},
        {"GREATCLUB",      {"GREATCLUB",      d8,  1, 1, 2,  false, 0, {0,   0}}},
        {"HANDAXE",        {"HANDAXE",        d6,  1, 1, 12, false, 2, {20,  60}}},
        {"JAVELIN",        {"JAVELIN",        d6,  1, 1, 8,  false, 2, {30,  120}}},
        {"LIGHT HAMMER",   {"LIGHT HAMMER",   d4,  1, 1, 2,  false, 2, {20,  60}}},
        {"MACE",           {"MACE",           d6,  1, 1, 2,  false, 0, {0,   0}}},
        {"QUARTERSTAFF",   {"QUARTERSTAFF",   d6,  1, 1, 2,  false, 0, {0,   0}}},
        {"QUARTERSTAFF+",  {"QUARTERSTAFF+",  d8,  1, 1, 2,  false, 0, {0,   0}}},
        {"SICKLE",         {"SICKLE",         d4,  1, 1, 12, false, 0, {0,   0}}},
        {"SPEAR",          {"SPEAR",          d6,  1, 1, 8,  false, 2, {20,  60}}},
        {"SPEAR+",         {"SPEAR+",         d8,  1, 1, 8,  false, 2, {20,  60}}},

        ///Simple Ranged Weapons
        {"LIGHT CROSSBOW", {"LIGHT CROSSBOW", d8,  1, 2, 8,  false, 1, {80,  320}}},
        {"DART",           {"DART",           d4,  1, 3, 8,  false, 3, {20,  60}}},
        {"SHORTBOW",       {"SHORTBOW",       d6,  1, 2, 8,  false, 1, {80,  320}}},
        {"SLING",          {"SLING",          d4,  1, 2, 2,  false, 1, {30,  120}}},

        ///Martial Melee Weapons
        {"BATTLEAXE",      {"BATLLEAXE",      d8,  1, 1, 12, true,  0, {0,   0}}},
        {"BATTLEAXE+",     {"BATTLEAXE+",     d10, 1, 1, 12, true,  0, {0,   0}}},
        {"FLAIL",          {"FLAIL",          d8,  1, 1, 2,  true,  0, {0,   0}}},
        {"GLAIVE",         {"GLAIVE",         d10, 1, 1, 12, true,  4, {0,   0}}},
        {"GREATAXE",       {"GREATAXE",       d12, 1, 1, 12, true,  0, {0,   0}}},
        {"GREATSWORD",     {"GREATSWORD",     d6,  2, 1, 12, true,  0, {0,   0}}},
        {"HALBERD",        {"HALBERD",        d10, 1, 1, 12, true,  4, {0,   0}}},
        {"LANCE",          {"LANCE",          d12, 1, 1, 8,  true,  4, {0,   0}}},
        {"LONGSWORD",      {"LONGSWORD",      d8,  1, 1, 12, true,  0, {0,   0}}},
        {"LONGSWORD+",     {"LONGSWORD+",     d10, 1, 1, 12, true,  0, {0,   0}}},
        {"MAUL",           {"MAUL",           d6,  2, 1, 2,  true,  0, {0,   0}}},
        {"MORNINGSTAR",    {"MORNINGSTAR",    d8,  1, 1, 8,  true,  0, {0,   0}}},
        {"PIKE",           {"PIKE",           d6,  1, 1, 8,  true,  4, {0,   0}}},
        {"RAPIER",         {"RAPIER",         d6,  1, 3, 8,  true,  0, {0,   0}}},
        {"SCIMITAR",       {"SCIMITAR",       d6,  1, 3, 8,  true,  0, {0,   0}}},
        {"SHORTSWORD",     {"SHORTSWORD",     d4,  1, 3, 8,  true,  0, {0,   0}}},
        {"TRIDENT",        {"TRIDENT",        d6,  1, 1, 8,  true,  2, {20,  60}}},
        {"TRIDENT+",       {"TRIDENT+",       d8,  1, 1, 8,  true,  2, {20,  60}}},
        {"WAR PICK",       {"WAR PICK",       d8,  1, 1, 8,  true,  0, {0,   0}}},
        {"WARHAMMER",      {"WARHAMMER",      d8,  1, 1, 2,  true,  0, {0,   0}}},
        {"WARHAMMER+",     {"WARHAMMER+",     d10, 1, 1, 2,  true,  0, {0,   0}}},
        {"WHIP",           {"WHIP",           d4,  1, 3, 12, true,  4, {0,   0}}},

        ///Martial Ranged Weapons
        {"BLOWGUN",        {"BLOWGUN",        d1,  1, 2, 8,  true,  1, {25,  100}}},
        {"HAND CROSSBOW",  {"HAND CROSSBOW",  d6,  1, 2, 8,  true,  1, {30,  120}}},
        {"HEAVY CROSSBOW", {"HEAVY CROSSBOW", d10, 1, 2, 8,  true,  1, {100, 400}}},
        {"LONGBOW",        {"LONGBOW",        d8,  1, 2, 8,  true,  1, {150, 600}}},
        {"NET",            {"NET",            d0,  1, 2, 0,  true,  3, {5,   15}}}
};

void weapons::addWeapon(const std::string &name, Weapons &stats) {
    weaps[name] = stats;
}

void weapons::delWeapon(const std::string &name) {
    weaps.erase(name);
}

int weapons::save(const std::string &file) {
    std::ofstream out;
    out.open(file);

    if (out.good()) {
        std::string delim = "$";

        for (auto const &[key, wea] : weaps) {
            out << key << delim;
            out << wea.name << delim;
            out << wea.die.nums << delim;
            out << wea.numberDice << delim;
            out << wea.ability << delim;
            out << wea.damageType << delim;
            out << wea.martial << delim;
            out << wea.ranged << delim;
            out << wea.range.first << delim;
            out << wea.range.second << std::endl;
        }

        out << weaps.size();
        out << "fin";

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

int weapons::load(const std::string &file) {
    std::ifstream fin;
    fin.open(file);

    if (fin.good()) {
        std::string tmp;
        std::string token;
        std::string delim = "$";
        size_t pos;
        std::vector<std::string> mapper;

        weaps.clear();

        while (getline(fin, tmp)) {
            if (tmp.substr(tmp.size() - 3, 3) == "fin") {
                if (weaps.size() != std::stoi(tmp.substr(0, tmp.size() - 3))) {
                    fin.close();

                    std::cerr << "ERROR WHEN READING" << std::endl;
                    return 0;
                } else {
                    break;
                }
            }

            mapper.clear();
            while ((pos = tmp.find(delim)) != std::string::npos) {
                token = tmp.substr(0, pos);
                mapper.push_back(token);
                tmp.erase(0, pos + delim.size());
            }
            mapper.push_back(tmp);

            weaps[mapper[0]] = {
                    mapper[1],
                    eztp::dice[std::stoi(mapper[2])],
                    static_cast<short>(std::stoi(mapper[3])),
                    static_cast<short>(std::stoi(mapper[4])),
                    static_cast<short>(std::stoi(mapper[5])),
                    static_cast<bool>(std::stoi(mapper[6])),
                    static_cast<short>(std::stoi(mapper[7])),
                    {
                            std::stoi(mapper[8]),
                            std::stoi(mapper[9])
                    }
            };

            tmp.clear();
        }
        fin.close();

        std::cout << "READ" << std::endl;
        return 1;
    } else {
        fin.close();

        std::cerr << "CAN'T READ" << std::endl;
        return 0;
    }
}