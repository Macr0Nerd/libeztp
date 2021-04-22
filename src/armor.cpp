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

#include "libeztp/armor.hpp"

namespace {
    std::map<std::string, eztp::Armor::ArmorStruct> armors;
}

void eztp::Armor::addArmor(const std::string &name, ArmorStruct &stats) {
    ::armors[name] = stats;
}

void eztp::Armor::delArmor(const std::string &name) {
    ::armors.erase(name);
}

eztp::Armor::ArmorStruct eztp::Armor::getArmor(const std::string &name) {
    return ::armors.at(name);
}

std::map<std::string, eztp::Armor::ArmorStruct> eztp::Armor::getArmors() {
    return ::armors;
}

bool eztp::Armor::load() {
    std::string armorDir = std::string(DATA_DIR) + "equipment-categories/armor/";
    std::string filename = armorDir + "armor.json";

    nlohmann::json json;
    std::ifstream inf;

    std::string n, cat;
    int base, dex, str;
    bool stealth;

    for (const auto& entry : std::filesystem::directory_iterator(armorDir)) {
        try {
            if (entry.path() != filename) {
                inf.open(entry.path());

                inf >> json;

                n = json["name"];
                cat = json["armor_category"];

                base = json["armor_class"]["base"];
                dex = json["armor_class"]["dex_bonus"].get<bool>() ? (json["armor_class"]["max_bonus"].is_null() ? 10 : json["armor_class"]["max_bonus"].get<int>()) : 0;

                str = json["str_minimum"];

                stealth = json["stealth_disadvantage"];

                ::armors[json["index"]] = {n,
                                           base,
                                           dex,
                                           cat,
                                           stealth,
                                           str};

                inf.close();
            }
        } catch (std::exception& e) {
            inf.close();
            continue;
        }
    }

    return true;
}