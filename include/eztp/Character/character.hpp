#pragma once

#ifndef EZTPLIB_CHARACTER_HPP
#define EZTPLIB_CHARACTER_HPP

#include "eztp/Core/dice.hpp"
#include "eztp/Character/armor.hpp"
#include "eztp/Character/weapons.hpp"
#include "eztp/Character/race.hpp"
#include "eztp/Character/background.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <array>
#include <utility>
#include <cmath>
#include <algorithm>

namespace eztp::character {
    class character {
    public:
        ///Used to keep track of characters; 0 is for placeholder, 1-1000 is for NPCs, 1001+ is for PCs
        unsigned long uid = 0;

        bool npc = false;

        std::string cname, cclass, crace, cbg;
        int clevel;
        std::map<std::string, std::array<int, 2> > abilities;

        int hp = 0;
        int maxHP = 0;
        int ac = abilities["DEX"][1] + 10;
        int gp = 0;
        unsigned int speed = 30;

        std::vector<std::string> equipment = {"FISTS", "UNARMORED", "UNSHIELDED"}; ///Equipped items
        std::vector<std::string> misc = {}; ///Other items
        unsigned short proBonus = 2;
        std::map<std::string, std::string> traits;
        std::vector<std::string> proficiencies;
        std::vector<std::string> languages = {"COMMON"};
        std::vector<std::string> saves;
        std::vector<std::string> conditions;

        char size = 'M'; ///Sets the size

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

        ~character() = default;

        bool operator==(const character &a) const;

        bool operator==(const character &a);

        character &operator=(const character &a);

        character &operator>>(const character &a);

        void refreshMods();

        void refreshAC();

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

        void damage(int dmg);

        void heal(int heal);

        int rollSkill(const std::string &skill);

        void save(const std::string &file);

        void load(const std::string &file);

    private:
        ///Mapping the skills to an ability
        std::map<std::string, std::string> skills = {
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


#endif //EZTPLIB_CHARACTER_HPP
