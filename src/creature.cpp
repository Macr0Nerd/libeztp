/*
 *  Copyright (C) 2020  Gabriele A. Ron
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "libeztp/creature.hpp"

using namespace eztp;

Creature::Creature(std::string inName,
                   short inAC, std::string inAlignment,
                   int inHP,
                   char inSize,
                   unsigned int inSpeed,
                   std::string inType,
                   short strength,
                   short dexterity,
                   short constitution,
                   short intelligence,
                   short wisdom,
                   short charisma)
        : name(inName),
          ac(inAC),
          alignment(inAlignment),
          hp(inHP),
          maxHP(inHP),
          size(inSize),
          speed(inSpeed) {
    abilities = {{"STR", strength},
                 {"DEX", dexterity},
                 {"CON", constitution},
                 {"INT", intelligence},
                 {"WIS", wisdom},
                 {"CHA", charisma}};
}

std::string Creature::getName() const {
    return name;
}

void Creature::setName(std::string &inName) {
    name = inName;
}

std::map<std::string, short> Creature::getAbilities() const {
    return abilities;
}

void Creature::setAbilities(std::map<std::string, short> &inAbilities) {
    abilities = inAbilities;
}

int Creature::getAbility(std::string &ability) const {
    return abilities.at(ability);
}

void Creature::setAbility(std::string &ability, short value) {
    abilities[ability] = value;
}

short Creature::getAC() const {
    return ac;
}

void Creature::setAC(short inAC) {
    ac = inAC;
}

std::string Creature::getAlignment() const {
    return alignment;
}

void Creature::setAlignment(std::string &inAlignment) {
    alignment = inAlignment;
}

int Creature::getHP() const {
    return hp;
}

void Creature::setHP(int inHP) {
    hp = inHP;
}

char Creature::getSize() const {
    return size;
}

void Creature::setSize(char inSize) {
    size = inSize;
}

unsigned int Creature::getSpeed() const {
    return speed;
}

void Creature::setSpeed(unsigned int inSpeed) {
    speed = inSpeed;
}

std::string Creature::getType() const {
    return type;
}

void Creature::setType(std::string &inType) {
    type = inType;
}

void Creature::heal(int value) {
    if(hp + value <= maxHP)
        hp += value;
}

void Creature::damage(int value) {
    hp -= value;
}