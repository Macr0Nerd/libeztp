#pragma once

#ifndef LIBEZTP_ARMOR_HPP
#define LIBEZTP_ARMOR_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <nlohmann/json.hpp>

namespace eztp::Armor {
    struct ArmorStruct {
        std::string name;
        unsigned short baseAC; ///The base amount the armour protects with 0 dex
        unsigned short dexMax; ///The amount of allowed dex (0 = no dex, 10 = no limit)
        char armType; ///'N' = None, L' = Light, 'M' = Medium, 'H' = Heavy
        bool disadvantage; ///Whether there is disadvantage on stealth or not
        unsigned short don; ///The time -- in minutes -- it takes to don the armor
        unsigned short doff; ///The time -- in minutes -- it takes to doff the armor
        unsigned short strength; ///The minimum required strength

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ArmorStruct, name, baseAC, dexMax, armType, disadvantage, don, doff, strength)
    };

    void addArmor(const std::string &name, ArmorStruct &stats);

    void delArmor(const std::string &name);

    [[nodiscard]] ArmorStruct getArmor(const std::string &name);

    [[nodiscard]] std::map<std::string, ArmorStruct> getArmors();

    [[nodiscard]] bool save(const std::string &filename = "armor.json");

    [[nodiscard]] bool load(const std::string &filename = "armor.json");
}

#endif //LIBEZTP_ARMOR_HPP
