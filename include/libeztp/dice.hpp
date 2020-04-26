#pragma once

#ifndef LIBEZTP_DICE_HPP
#define LIBEZTP_DICE_HPP

#include <chrono>
#include <random>
#include <map>

namespace eztp {
    class dice {
    public:
        int nums;

        explicit dice(int sides = -1);

        ~dice() = default;

        [[nodiscard]] int roll() const;

        dice &operator=(const dice &a) = default;

        bool operator==(const dice &a) const;

        bool operator!=(const dice &a) const;
    };

    extern dice d0;
    extern dice d1;
    extern dice d2;
    extern dice d4;
    extern dice d6;
    extern dice d8;
    extern dice d10;
    extern dice d12;
    extern dice d20;
    extern dice d100;

    typedef std::map<int, dice> dmap;
    static dmap dices;
}

#endif /* LIBEZTP_DICE_HPP */