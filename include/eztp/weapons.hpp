#pragma once

#ifndef EZTPLIB_WEAPONS_HPP
#define EZTPLIB_WEAPONS_HPP

#include "dice.hpp"
#include <string>
#include <map>
#include <iostream>
#include <fstream>

namespace eztp::character {
    class weapons {
    public:
        struct Weapons {
            std::string name;
            core::dice die;
            short numberDice;
            short ability; ///1 = Strength, 2 = Dexterity, 3 = Finesse
            short damageType; ///0 = None, 1 = Acid, 2 = Bludgeoning, 3 = Cold, 4 = Fire, 5 = Force, 6 = Lightning, 7 = Necrotic, 8 = Piercing, 9 = Poison, 10 = Psychic, 11 = Radiant, 12 = Slashing, 13 = Thunder
            bool martial;
            short ranged; ///0 = Melee, 1 = Ranged, 2 = Thrown, 3 = Ranged/Thrown, 4 = Reach
            std::pair<int, int> range;
        };

        typedef std::map<std::string, Weapons> wmap;
        static wmap weaps;

        weapons() = default;

        ~weapons() = default;

        static void addWeapon(const std::string &name, Weapons &stats);

        static void delWeapon(const std::string &name);

        static int save(const std::string &file);

        static int load(const std::string &file);
    };
}

#endif //EZTPLIB_WEAPONS_HPP
