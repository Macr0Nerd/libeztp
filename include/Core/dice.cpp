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

core::dice d0(0);
core::dice d1(1);
core::dice d2(2);
core::dice d4(4);
core::dice d6(6);
core::dice d8(8);
core::dice d10(10);
core::dice d12(12);
core::dice d20(20);
core::dice d100(100);