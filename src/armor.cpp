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
    std::map<std::string, eztp::Armor::ArmorStruct> armors = {
            {"UNARMORED",       {"UNARMORED",       10, 10, 'N', false, 0,  0, 0}},
            {"PADDED",          {"PADDED",          11, 10, 'L', true,  1,  1, 0}},
            {"LEATHER",         {"LEATHER",         11, 10, 'L', false, 1,  1, 0}},
            {"STUDDED LEATHER", {"STUDDED LEATHER", 12, 10, 'L', false, 1,  1, 0}},
            {"HIDE",            {"HIDE",            12, 2,  'M', false, 5,  1, 0}},
            {"CHAIN SHIRT",     {"CHAIN SHIRT",     13, 2,  'M', false, 5,  1, 0}},
            {"SCALE MAIL",      {"SCALE MAIL",      14, 2,  'M', true,  5,  1, 0}},
            {"BREASTPLATE",     {"BREASTPLATE",     14, 2,  'M', false, 5,  1, 0}},
            {"HALF PLATE",      {"HALF PLATE",      15, 2,  'M', true,  5,  1, 0}},
            {"RING MAIL",       {"RING MAIL",       14, 0,  'H', true,  10, 5, 0}},
            {"CHAIN MAIL",      {"CHAIN MAIL",      16, 0,  'H', true,  10, 1, 13}},
            {"SPLINT",          {"SPLINT",          17, 0,  'H', true,  10, 5, 15}},
            {"PLATE",           {"PLATE",           18, 0,  'H', true,  10, 5, 15}}
    };
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

bool eztp::Armor::save(const std::string &filename) {
    std::ofstream out(filename);

    if (out.good()) {
        try {
            nlohmann::json js(::armors);

            out << js << std::endl;

            out.close();

            return true;
        } catch (...) {
            out.close();
            return false;
        }
    } else {
        out.close();
        return false;
    }
}

bool eztp::Armor::load(const std::string &filename) {
    std::ifstream in(filename);

    if (in.good()) {
        try {
            nlohmann::json js, tmp;
            in >> js;
            ::armors.clear();
            ::armors = js.get<std::map<std::string, ArmorStruct>>();

            in.close();
            return true;
        } catch (...) {
            in.close();
            return false;
        }
    } else {
        in.close();
        return false;
    }
}