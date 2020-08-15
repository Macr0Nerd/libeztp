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
    std::map<std::string, eztp::Weapons::WeaponStruct> weaps = {
            {"FISTS",          {"FISTS",          eztp::dice.at(1),  1, 1, 2,  false, 0, {0,   0}}},
            {"CLUB",           {"CLUB",           eztp::dice.at(4),  1, 1, 2,  false, 0, {0,   0}}},
            {"DAGGER",         {"DAGGER",         eztp::dice.at(4),  1, 3, 8,  false, 2, {20,  60}}},
            {"GREATCLUB",      {"GREATCLUB",      eztp::dice.at(8),  1, 1, 2,  false, 0, {0,   0}}},
            {"HANDAXE",        {"HANDAXE",        eztp::dice.at(6),  1, 1, 12, false, 2, {20,  60}}},
            {"JAVELIN",        {"JAVELIN",        eztp::dice.at(6),  1, 1, 8,  false, 2, {30,  120}}},
            {"LIGHT HAMMER",   {"LIGHT HAMMER",   eztp::dice.at(4),  1, 1, 2,  false, 2, {20,  60}}},
            {"MACE",           {"MACE",           eztp::dice.at(6),  1, 1, 2,  false, 0, {0,   0}}},
            {"QUARTERSTAFF",   {"QUARTERSTAFF",   eztp::dice.at(6),  1, 1, 2,  false, 0, {0,   0}}},
            {"QUARTERSTAFF+",  {"QUARTERSTAFF+",  eztp::dice.at(8),  1, 1, 2,  false, 0, {0,   0}}},
            {"SICKLE",         {"SICKLE",         eztp::dice.at(4),  1, 1, 12, false, 0, {0,   0}}},
            {"SPEAR",          {"SPEAR",          eztp::dice.at(6),  1, 1, 8,  false, 2, {20,  60}}},
            {"SPEAR+",         {"SPEAR+",         eztp::dice.at(8),  1, 1, 8,  false, 2, {20,  60}}},

            ///Simple Ranged Weapons
            {"LIGHT CROSSBOW", {"LIGHT CROSSBOW", eztp::dice.at(8),  1, 2, 8,  false, 1, {80,  320}}},
            {"DART",           {"DART",           eztp::dice.at(4),  1, 3, 8,  false, 3, {20,  60}}},
            {"SHORTBOW",       {"SHORTBOW",       eztp::dice.at(6),  1, 2, 8,  false, 1, {80,  320}}},
            {"SLING",          {"SLING",          eztp::dice.at(4),  1, 2, 2,  false, 1, {30,  120}}},

            ///Martial Melee Weapons
            {"BATTLEAXE",      {"BATLLEAXE",      eztp::dice.at(8),  1, 1, 12, true,  0, {0,   0}}},
            {"BATTLEAXE+",     {"BATTLEAXE+",     eztp::dice.at(10), 1, 1, 12, true,  0, {0,   0}}},
            {"FLAIL",          {"FLAIL",          eztp::dice.at(8),  1, 1, 2,  true,  0, {0,   0}}},
            {"GLAIVE",         {"GLAIVE",         eztp::dice.at(10), 1, 1, 12, true,  4, {0,   0}}},
            {"GREATAXE",       {"GREATAXE",       eztp::dice.at(12), 1, 1, 12, true,  0, {0,   0}}},
            {"GREATSWORD",     {"GREATSWORD",     eztp::dice.at(6),  2, 1, 12, true,  0, {0,   0}}},
            {"HALBERD",        {"HALBERD",        eztp::dice.at(10), 1, 1, 12, true,  4, {0,   0}}},
            {"LANCE",          {"LANCE",          eztp::dice.at(12), 1, 1, 8,  true,  4, {0,   0}}},
            {"LONGSWORD",      {"LONGSWORD",      eztp::dice.at(8),  1, 1, 12, true,  0, {0,   0}}},
            {"LONGSWORD+",     {"LONGSWORD+",     eztp::dice.at(10), 1, 1, 12, true,  0, {0,   0}}},
            {"MAUL",           {"MAUL",           eztp::dice.at(6),  2, 1, 2,  true,  0, {0,   0}}},
            {"MORNINGSTAR",    {"MORNINGSTAR",    eztp::dice.at(8),  1, 1, 8,  true,  0, {0,   0}}},
            {"PIKE",           {"PIKE",           eztp::dice.at(6),  1, 1, 8,  true,  4, {0,   0}}},
            {"RAPIER",         {"RAPIER",         eztp::dice.at(6),  1, 3, 8,  true,  0, {0,   0}}},
            {"SCIMITAR",       {"SCIMITAR",       eztp::dice.at(6),  1, 3, 8,  true,  0, {0,   0}}},
            {"SHORTSWORD",     {"SHORTSWORD",     eztp::dice.at(4),  1, 3, 8,  true,  0, {0,   0}}},
            {"TRIDENT",        {"TRIDENT",        eztp::dice.at(6),  1, 1, 8,  true,  2, {20,  60}}},
            {"TRIDENT+",       {"TRIDENT+",       eztp::dice.at(8),  1, 1, 8,  true,  2, {20,  60}}},
            {"WAR PICK",       {"WAR PICK",       eztp::dice.at(8),  1, 1, 8,  true,  0, {0,   0}}},
            {"WARHAMMER",      {"WARHAMMER",      eztp::dice.at(8),  1, 1, 2,  true,  0, {0,   0}}},
            {"WARHAMMER+",     {"WARHAMMER+",     eztp::dice.at(10), 1, 1, 2,  true,  0, {0,   0}}},
            {"WHIP",           {"WHIP",           eztp::dice.at(4),  1, 3, 12, true,  4, {0,   0}}},

            ///Martial Ranged Weapons
            {"BLOWGUN",        {"BLOWGUN",        eztp::dice.at(1),  1, 2, 8,  true,  1, {25,  100}}},
            {"HAND CROSSBOW",  {"HAND CROSSBOW",  eztp::dice.at(6),  1, 2, 8,  true,  1, {30,  120}}},
            {"HEAVY CROSSBOW", {"HEAVY CROSSBOW", eztp::dice.at(10), 1, 2, 8,  true,  1, {100, 400}}},
            {"LONGBOW",        {"LONGBOW",        eztp::dice.at(8),  1, 2, 8,  true,  1, {150, 600}}},
            {"NET",            {"NET",            eztp::dice.at(0),  1, 2, 0,  true,  3, {5,   15}}}
    };
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