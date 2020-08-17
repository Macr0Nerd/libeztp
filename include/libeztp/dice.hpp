#pragma once

#ifndef LIBEZTP_DICE_HPP
#define LIBEZTP_DICE_HPP

#include <chrono>
#include <random>
#include <map>
#include <nlohmann/json.hpp>

namespace eztp {
    class Die {
    public:
        explicit Die(int sides = -1);

        ~Die() = default;

        [[nodiscard]] int roll();

        Die &operator=(const Die &a) = default;

        bool operator==(const Die &a) const;

        bool operator!=(const Die &a) const;

        [[nodiscard]] int getSides() const;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Die, nums)

    private:
        int nums;

        unsigned seed;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;
    };

    extern std::map<int, Die> dice;
}

#endif /* LIBEZTP_DICE_HPP */