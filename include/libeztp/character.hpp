#pragma once

#ifndef LIBEZTP_CHARACTER_HPP
#define LIBEZTP_CHARACTER_HPP

#include "dice.hpp"
#include "creature.hpp"
#include "armor.hpp"
#include "weapons.hpp"
#include "race.hpp"
#include "background.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <array>
#include <utility>
#include <cmath>
#include <algorithm>

namespace eztp {
    class character : creature {
    public:
        character(const std::string &initname,
                  const std::string &initclass,
                  const std::string &initrace,
                  const std::string &initbg,
                  int level = 1,
                  int strength = 10,
                  int dexterity = 10,
                  int constitution = 10,
                  int intelligence = 10,
                  int wisdom = 10,
                  int charisma = 10,
                  bool isNPC = false,
                  unsigned long id = 0);

        ~character() override = default;

        bool operator==(const character &a) const;

        character &operator=(const character &a);

        void softCopy(const character &a);

        void addTrait(const std::string &name, const std::string &description);

        void delTrait(const std::string &name);

        void addProf(const std::string &name);

        void delProf(const std::string &name);

        void addItem(const std::string &name);

        void delItem(const std::string &name);

        void addCondition(const std::string &name);

        void delCondition(const std::string &name);

        void setWeapon(const std::string &inWeapon);

        void setArmor(const std::string &inArmor);

        std::string getWeapon();

        std::string getArmor();

        int attack(bool mod = true);

        int rollSkill(const std::string &skill);

    private:
        unsigned long uid = 0;

        bool npc = false;

        std::string cclass, crace, cbg;
        int clevel;
        int gp = 0;

        std::vector<std::string> equipment = {"FISTS", "UNARMORED", "UNSHIELDED"}; ///Equipped items
        std::vector<std::string> misc = {}; ///Other items
        unsigned short proBonus = 2;
        std::map<std::string, std::string> traits;
        std::vector<std::string> proficiencies;
        std::vector<std::string> languages = {"COMMON"};
        std::vector<std::string> saves;
        std::vector<std::string> conditions;

        ///Mapping the skills to an ability
        const std::map<std::string, std::string> skills = {
                {"ATHLETICS",       "STR"},
                {"ACROBATICS",      "DEX"},
                {"SLEIGHT OF HAND", "DEX"},
                {"STEALTH",         "DEX"},
                {"ARCANA",          "INT"},
                {"HISTORY",         "INT"},
                {"INVESTIGATION",   "INT"},
                {"NATURE",          "INT"},
                {"RELIGION",        "INT"},
                {"ANIMAL HANDLING", "WIS"},
                {"INSIGHT",         "WIS"},
                {"MEDICINE",        "WIS"},
                {"PERCEPTION",      "WIS"},
                {"SURVIVAL",        "WIS"},
                {"DECEPTION",       "CHA"},
                {"INTIMIDATION",    "CHA"},
                {"PERFORMANCE",     "CHA"},
                {"PERSUASION",      "CHA"}
        };

        ///0 = None, 1 = Acid, 2 = Bludgeoning, 3 = Cold, 4 = Fire, 5 = Force, 6 = Lightning, 7 = Necrotic, 8 = Piercing, 9 = Poison, 10 = Psychic, 11 = Radiant, 12 = Slashing, 13 = Thunder
        std::vector<int> vulnerabilities = {0};
        std::vector<int> immunities = {0};
        std::vector<int> resistances = {0};

        void setRace(const std::string &name);

        void setBG(const std::string &name);
    };
}


#endif //LIBEZTP_CHARACTER_HPP
