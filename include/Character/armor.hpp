#pragma once

#ifndef EZTPLIB_ARMOR_HPP
#define EZTPLIB_ARMOR_HPP

#include "Core/dice.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

namespace eztp::character {
    class armor {
    public:
        struct Armor {
            std::string name;
            unsigned short baseAC; ///The base amount the armour protects with 0 dex
            unsigned short dexMax; ///The amount of allowed dex (0 = no dex, 10 = no limit)
            char armType; ///'N' = None, L' = Light, 'M' = Medium, 'H' = Heavy
            bool disadvantage; ///Whether there is disadvantage on stealth or not
            unsigned short don; ///The time -- in minutes -- it takes to don the armor
            unsigned short doff; ///The time -- in minutes -- it takes to doff the armor
            unsigned short strength; ///The minimum required strength
        };

        typedef std::map<std::string, Armor> amap;
        static amap armors;

        armor() = default;

        ~armor() = default;

        static void addArmor(const std::string &name, Armor &stats);

        static void delArmor(const std::string &name);

        static void save(const std::string &file);

        static void load(const std::string &file);
    };
}

#endif //EZTPLIB_ARMOR_HPP
