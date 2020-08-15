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

#include "libeztp/dice.hpp"

eztp::Die::Die(int sides) : nums(sides), seed(std::chrono::system_clock::now().time_since_epoch().count()),
                            generator(seed), distribution(1, nums) {}

int eztp::Die::roll() {
    if (nums > 0) {
        return distribution(generator);
    } else {
        return nums;
    }
}

bool eztp::Die::operator==(const Die &a) const {
    return nums == a.nums;
}

bool eztp::Die::operator!=(const Die &a) const {
    return nums != a.nums;
}

int eztp::Die::getSides() const {
    return nums;
}

std::map<int, eztp::Die> eztp::dice = {
        {0,   eztp::Die(0)},
        {1,   eztp::Die(1)},
        {2,   eztp::Die(2)},
        {4,   eztp::Die(4)},
        {6,   eztp::Die(6)},
        {8,   eztp::Die(8)},
        {10,  eztp::Die(10)},
        {12,  eztp::Die(12)},
        {20,  eztp::Die(20)},
        {100, eztp::Die(100)}
};