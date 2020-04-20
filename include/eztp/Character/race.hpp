#pragma once

#ifndef EZTPLIB_RACE_HPP
#define EZTPLIB_RACE_HPP

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

namespace eztp::character {
    class race {
    public:
        struct Race {
            std::string name;
            std::vector<std::string> abis; ///Abilities to improve
            std::vector<unsigned short> boosts; ///How much to improve them by

            char size;

            unsigned int speed;

            std::map<std::string, std::string> traits;
            std::vector<std::string> prof;
        };

        typedef std::map<std::string, Race> rmap;
        static rmap races;

        race() = default;

        ~race() = default;

        static void addRace(const std::string &name, Race &stats);

        static void delRace(const std::string &name);

        static int save(const std::string &file);

        static int load(const std::string &file);
    };
}


#endif //EZTPLIB_RACE_HPP
