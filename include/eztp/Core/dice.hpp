#pragma once

#ifndef EZTPLIB_DICE_HPP
#define EZTPLIB_DICE_HPP

#include <chrono>
#include <random>
#include <map>

namespace eztp {
    namespace core {
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
    }

    extern core::dice d0;
    extern core::dice d1;
    extern core::dice d2;
    extern core::dice d4;
    extern core::dice d6;
    extern core::dice d8;
    extern core::dice d10;
    extern core::dice d12;
    extern core::dice d20;
    extern core::dice d100;

    typedef std::map<int, core::dice> dmap;
    static dmap dice;
}

#endif /* EZTPLIB_DICE_HPP */