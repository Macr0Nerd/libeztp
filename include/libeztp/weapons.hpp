#pragma once

#ifndef LIBEZTP_WEAPONS_HPP
#define LIBEZTP_WEAPONS_HPP

#include "dice.hpp"
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>

namespace eztp::Weapons {
    struct WeaponStruct {
        std::string name; /// If the name has a +, it is the versatile version. If it has a *, it is the thrown version.
        Die die;
        short numberDice;
        std::string damageType;
        std::string weapType;
        std::pair<int, int> range;
        std::vector<std::string> properties;
    };

    void addWeapon(const std::string &name, WeaponStruct &stats);

    void delWeapon(const std::string &name);

    [[nodiscard]] WeaponStruct getWeapon(const std::string &name);

    [[nodiscard]] std::map<std::string, WeaponStruct> getWeapons();

    [[nodiscard]] bool load();
}

#endif //LIBEZTP_WEAPONS_HPP
