#pragma once

#ifndef LIBEZTP_ARMOR_HPP
#define LIBEZTP_ARMOR_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <filesystem>
#include <nlohmann/json.hpp>

namespace eztp::Armor {
    struct ArmorStruct {
        std::string name;
        int baseAC; ///The base amount the armour protects with 0 dex
        int dexMax; ///The amount of allowed dex (0 = no dex, 10 = no limit)
        std::string armType;
        bool disadvantage; ///Whether there is disadvantage on stealth or not
        int strength; ///The minimum required strength
    };

    void addArmor(const std::string &name, ArmorStruct &stats);

    void delArmor(const std::string &name);

    [[nodiscard]] ArmorStruct getArmor(const std::string &name);

    [[nodiscard]] std::map<std::string, ArmorStruct> getArmors();

    [[nodiscard]] bool load();
}

#endif //LIBEZTP_ARMOR_HPP
