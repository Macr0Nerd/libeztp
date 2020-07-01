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

creature::creature(std::string inName,
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
          size(inSize),
          speed(inSpeed) {
    abilities = {{"STR", strength},
                 {"DEX", dexterity},
                 {"CON", constitution},
                 {"INT", intelligence},
                 {"WIS", wisdom},
                 {"CHA", charisma}};
}

std::string creature::getName() const {
    return name;
}

void creature::setName(std::string &inName) {
    name = inName;
}

std::map<std::string, short> creature::getAbilities() const {
    return abilities;
}

void creature::setAbilities(std::map<std::string, short> &inAbilities) {
    abilities = inAbilities;
}

int creature::getAbility(std::string &ability) const {
    return abilities.at(ability);
}

void creature::setAbility(std::string &ability, short value) {
    abilities[ability] = value;
}

short creature::getAC() const {
    return ac;
}

void creature::setAC(short inAC) {
    ac = inAC;
}

std::string creature::getAlignment() const {
    return alignment;
}

void creature::setAlignment(std::string &inAlignment) {
    alignment = inAlignment;
}

int creature::getHP() const {
    return hp;
}

void creature::setHP(int inHP) {
    hp = inHP;
}

char creature::getSize() const {
    return size;
}

void creature::setSize(char inSize) {
    size = inSize;
}

unsigned int creature::getSpeed() const {
    return speed;
}

void creature::setSpeed(unsigned int inSpeed) {
    speed = inSpeed;
}

std::string creature::getType() const {
    return type;
}

void creature::setType(std::string &inType) {
    type = inType;
}

void creature::heal(int value) {
    hp += value;
}

void creature::damage(int value) {
    hp -= value;
}