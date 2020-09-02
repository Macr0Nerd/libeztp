#pragma once

#ifndef LIBEZTP_CREATURE_HPP
#define LIBEZTP_CREATURE_HPP

#include <string>
#include <map>
#include <array>

namespace eztp {
    class Creature {
    public:
        Creature(std::string inName = "",
                 short inAC = 0,
                 std::string inAlignment = "",
                 int inHP = 0, char inSize = 'M',
                 unsigned int inSpeed = 0,
                 std::string inType = "",
                 short strength = 10,
                 short dexterity = 10,
                 short constitution = 10,
                 short intelligence = 10,
                 short wisdom = 10,
                 short charisma = 10);

        virtual ~Creature() = default;

        //Getters and Setters for the class members
        std::string getName() const;

        void setName(std::string &inName);

        [[nodiscard]] std::map<std::string, short> getAbilities() const;

        void setAbilities(std::map<std::string, short> &inAbilities);

        int getAbility(std::string &ability) const;

        void setAbility(std::string &ability, short value);

        short getAC() const;

        void setAC(short inAC);

        std::string getAlignment() const;

        void setAlignment(std::string &inAlignment);

        int getHP() const;

        void setHP(int inHP);

        char getSize() const;

        void setSize(char inSize);

        unsigned int getSpeed() const;

        void setSpeed(unsigned int inSpeed);

        std::string getType() const;

        void setType(std::string &inType);

        //Other Functions
        void heal(int value);

        void damage(int value);

    protected:
        std::string name;

        std::map<std::string, short> abilities;
        short ac;
        std::string alignment;
        int hp;
        int maxHP;
        char size;
        unsigned int speed;
        std::string type;
    };
}


#endif //LIBEZTP_CREATURE_HPP
