#pragma once

#ifndef LIBEZTP_RACE_HPP
#define LIBEZTP_RACE_HPP

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

namespace eztp {
    class Race {
    public:
        struct RaceStruct {
            std::string name;
            std::vector<std::string> abis; ///Abilities to improve
            std::vector<unsigned short> boosts; ///How much to improve them by

            char size;

            unsigned int speed;

            std::map<std::string, std::string> traits;
            std::vector<std::string> prof;
        };

        Race() = default;

        ~Race() = default;

        static void addRace(const std::string &name, RaceStruct &stats);

        static void delRace(const std::string &name);

        [[nodiscard]] static RaceStruct getRace(const std::string &name);

        [[nodiscard]] static bool save(const std::string &filename = "race.json");

        [[nodiscard]] static bool load(const std::string &filename = "race.json");
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Race::RaceStruct, name, abis, boosts, size, speed, traits, prof)
}


#endif //LIBEZTP_RACE_HPP
