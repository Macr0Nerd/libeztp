#include "dice.hpp"

using namespace eztp;

core::dice::dice(int sides) {
    nums = sides;
}

int core::dice::roll() const {
    if (nums > 0) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);

        std::uniform_int_distribution<int> distribution(1, nums);

        return distribution(generator);
    } else {
        return nums;
    }
}

bool core::dice::operator==(const dice &a) const {
    return nums == a.nums;
}

bool core::dice::operator!=(const dice &a) const {
    return nums != a.nums;
}

core::dice eztp::d0(0);
core::dice eztp::d1(1);
core::dice eztp::d2(2);
core::dice eztp::d4(4);
core::dice eztp::d6(6);
core::dice eztp::d8(8);
core::dice eztp::d10(10);
core::dice eztp::d12(12);
core::dice eztp::d20(20);
core::dice eztp::d100(100);

dmap dice = {
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