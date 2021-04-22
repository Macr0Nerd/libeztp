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

#include "libeztp/weapons.hpp"

namespace {
    std::map<std::string, eztp::Weapons::WeaponStruct> weaps;
}

void eztp::Weapons::addWeapon(const std::string &name, WeaponStruct &stats) {
    ::weaps[name] = stats;
}

void eztp::Weapons::delWeapon(const std::string &name) {
    ::weaps.erase(name);
}

eztp::Weapons::WeaponStruct eztp::Weapons::getWeapon(const std::string &name) {
    return ::weaps.at(name);
}

std::map<std::string, eztp::Weapons::WeaponStruct> eztp::Weapons::getWeapons() {
    return ::weaps;
}

bool eztp::Weapons::load() {
    std::string weaponDir = std::string(DATA_DIR) + "equipment-categories/weapon/";
    std::string filename = weaponDir + "weapon.json";

    nlohmann::json json;
    std::ifstream inf;

    std::string fn, dam, cat, abi;
    std::stringstream tmp;
    std::pair<int, int> ran;
    int num;
    Die ddie;

    for (const auto& entry : std::filesystem::directory_iterator(weaponDir)) {
        tmp.clear();

        try {
            if (entry.path() != filename) {
                inf.open(entry.path());

                inf >> json;

                fn = json["damage"]["damage_dice"];

                tmp << fn;

                fn.clear();

                std::getline(tmp, fn, 'd');
                num = std::stoi(fn);

                std::getline(tmp, fn);

                ddie = dice.find(std::stoi(fn)) == dice.end() ? Die(std::stoi(fn)) : dice.at(std::stoi(fn));
                dam = json["damage"]["damage_type"]["name"];

                cat = json["category_range"];

                ran = {json["range"]["normal"].get<int>(), json["range"]["long"].is_null() ? 0 : json["range"]["long"].get<int>()};


                ::weaps[json["index"]] = {json["name"].get<std::string>(),
                                          ddie,
                                          num,
                                          dam,
                                          cat,
                                          ran,
                                          {}};

                if (json.find("properties") != json.end()) {
                    for (auto &it : json["properties"]) {
                        ::weaps[json["index"].get<std::string>()].properties.push_back(it["name"]);
                    }
                }

                if (json.find("two_handed_damage") != json.end()) {
                    tmp.clear();

                    fn = json["two_handed_damage"]["damage_dice"];

                    tmp << fn;

                    fn.clear();

                    std::getline(tmp, fn, 'd');
                    num = std::stoi(fn);

                    std::getline(tmp, fn);

                    ddie = dice.find(std::stoi(fn)) == dice.end() ? Die(std::stoi(fn)) : dice.at(std::stoi(fn));
                    dam = json["two_handed_damage"]["damage_type"]["name"];

                    ::weaps[json["index"].get<std::string>() + "+"] = {json["name"].get<std::string>() + "+",
                                              ddie,
                                              num,
                                              dam,
                                              cat,
                                              ran,
                                              {}};

                    if (json.find("properties") != json.end()) {
                        for (auto &it : json["properties"]) {
                            ::weaps[json["index"].get<std::string>() + "+"].properties.push_back(it["name"]);
                        }
                    }
                }

                if (std::find(::weaps[json["index"].get<std::string>()].properties.begin(), ::weaps[json["index"].get<std::string>()].properties.begin(), "Thrown") != ::weaps[json["index"].get<std::string>()].properties.end()){
                    tmp.clear();

                    fn = json["damage"]["damage_dice"];

                    tmp << fn;

                    fn.clear();

                    std::getline(tmp, fn, 'd');
                    num = std::stoi(fn);

                    std::getline(tmp, fn);

                    ddie = dice.find(std::stoi(fn)) == dice.end() ? Die(std::stoi(fn)) : dice.at(std::stoi(fn));
                    dam = json["damage"]["damage_type"]["name"];

                    ran = {json["throw_range"]["normal"].get<int>(), json["throw_range"]["long"].is_null() ? 0 : json["throw_range"]["long"].get<int>()};

                    ::weaps[json["index"].get<std::string>() + "*"] = {json["name"].get<std::string>() + "*",
                                                                       ddie,
                                                                       num,
                                                                       dam,
                                                                       cat,
                                                                       ran,
                                                                       {}};

                    if (json.find("properties") != json.end()) {
                        for (auto &it : json["properties"]) {
                            ::weaps[json["index"].get<std::string>() + "*"].properties.push_back(it["name"]);
                        }
                    }
                }

                inf.close();
            }
        } catch (std::exception& e) {
            inf.close();
            continue;
        }
    }

    return true;
}