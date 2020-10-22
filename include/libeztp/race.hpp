#pragma once

#ifndef LIBEZTP_RACE_HPP
#define LIBEZTP_RACE_HPP

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

namespace eztp::Race {
    struct RaceStruct {
        std::string name;
        std::vector<std::string> abis; ///Abilities to improve
        std::vector<unsigned short> boosts; ///How much to improve them by

        char size;

        unsigned int speed;

        std::map<std::string, std::string> traits;
        std::vector<std::string> prof;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(RaceStruct, name, abis, boosts, size, speed, traits, prof)
    };

    void addRace(const std::string &name, RaceStruct &stats);

    void delRace(const std::string &name);

    [[nodiscard]] RaceStruct getRace(const std::string &name);

    [[nodiscard]] std::map<std::string, RaceStruct> getRaces();

    [[nodiscard]] bool save(const std::string &filename = "race.json");

    [[nodiscard]] bool load(const std::string &filename = "race.json");
}


#endif //LIBEZTP_RACE_HPP
