#pragma once

#ifndef LIBEZTP_ARMOR_HPP
#define LIBEZTP_ARMOR_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <nlohmann/json.hpp>

namespace eztp {
    class Armor {
    public:
        struct ArmorStruct {
            std::string name;
            unsigned short baseAC; ///The base amount the armour protects with 0 dex
            unsigned short dexMax; ///The amount of allowed dex (0 = no dex, 10 = no limit)
            char armType; ///'N' = None, L' = Light, 'M' = Medium, 'H' = Heavy
            bool disadvantage; ///Whether there is disadvantage on stealth or not
            unsigned short don; ///The time -- in minutes -- it takes to don the armor
            unsigned short doff; ///The time -- in minutes -- it takes to doff the armor
            unsigned short strength; ///The minimum required strength
        };

        Armor() = default;

        ~Armor() = default;

        static void addArmor(const std::string &name, ArmorStruct &stats);

        static void delArmor(const std::string &name);

        [[nodiscard]] static ArmorStruct getArmor(const std::string &name);

        [[nodiscard]] static std::map<std::string, ArmorStruct> getArmors();

        [[nodiscard]] static bool save(const std::string &filename = "armor.json");

        [[nodiscard]] static bool load(const std::string &filename = "armor.json");
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Armor::ArmorStruct, name, baseAC, dexMax, armType, disadvantage, don, doff, strength)
}

#endif //LIBEZTP_ARMOR_HPP
