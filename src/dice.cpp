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

using namespace eztp;

dice::dice(int sides) {
    nums = sides;
}

int dice::roll() const {
    if (nums > 0) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);

        std::uniform_int_distribution<int> distribution(1, nums);

        return distribution(generator);
    } else {
        return nums;
    }
}

bool dice::operator==(const dice &a) const {
    return nums == a.nums;
}

bool dice::operator!=(const dice &a) const {
    return nums != a.nums;
}

dice eztp::d0(0);
dice eztp::d1(1);
dice eztp::d2(2);
dice eztp::d4(4);
dice eztp::d6(6);
dice eztp::d8(8);
dice eztp::d10(10);
dice eztp::d12(12);
dice eztp::d20(20);
dice eztp::d100(100);

dmap dices = {
        {0, eztp::d0},
        {1, eztp::d1},
        {2, eztp::d2},
        {4, eztp::d4},
        {6, eztp::d6},
        {8, eztp::d8},
        {10, eztp::d10},
        {12, eztp::d12},
        {20, eztp::d20},
        {100, eztp::d100}
};