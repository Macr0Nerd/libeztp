#pragma once

#ifndef EZTPLIB_DICE_HPP
#define EZTPLIB_DICE_HPP

#include <chrono>
#include <random>

namespace eztp {
    namespace core {
        class dice {
        public:
            explicit dice(int sides = -1);

            ~dice() = default;

            [[nodiscard]] int roll() const;

            dice &operator=(const dice &a) = default;

            bool operator==(const dice &a) const;

            bool operator!=(const dice &a) const;

        private:
            int nums;
        };
    }

    static core::dice d0;
    static core::dice d1;
    static core::dice d2;
    static core::dice d4;
    static core::dice d6;
    static core::dice d8;
    static core::dice d10;
    static core::dice d12;
    static core::dice d20;
    static core::dice d100;
}

#endif /* EZTPLIB_DICE_HPP */