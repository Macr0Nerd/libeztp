#pragma once

#ifndef LIBEZTP_WEAPONS_HPP
#define LIBEZTP_WEAPONS_HPP

#include "dice.hpp"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

namespace eztp::Weapons {
    struct WeaponStruct {
        std::string name;
        Die die;
        short numberDice;
        short ability; ///1 = Strength, 2 = Dexterity, 3 = Finesse
        short damageType; ///0 = None, 1 = Acid, 2 = Bludgeoning, 3 = Cold, 4 = Fire, 5 = Force, 6 = Lightning, 7 = Necrotic, 8 = Piercing, 9 = Poison, 10 = Psychic, 11 = Radiant, 12 = Slashing, 13 = Thunder
        bool martial;
        short ranged; ///0 = Melee, 1 = Ranged, 2 = Thrown, 3 = Ranged/Thrown, 4 = Reach
        std::pair<int, int> range;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(WeaponStruct, name, die, numberDice, ability, damageType, martial, ranged, range)
    };

    void addWeapon(const std::string &name, WeaponStruct &stats);

    void delWeapon(const std::string &name);

    [[nodiscard]] WeaponStruct getWeapon(const std::string &name);

    [[nodiscard]] std::map<std::string, WeaponStruct> getWeapons();

    [[nodiscard]] bool save(const std::string &filename = "weapons.json");

    [[nodiscard]] bool load(const std::string &filename = "weapons.json");
}

#endif //LIBEZTP_WEAPONS_HPP
