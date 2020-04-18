#pragma once

#ifndef EZTPLIB_RACE_HPP
#define EZTPLIB_RACE_HPP

#include <string>
#include <map>
#include <vector>

namespace eztp::character {
    class race {
    public:
        struct Race {
            std::string Name;
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

        static void add_race(const std::string &name, Race &stats);

        static void del_race(const std::string &name);
    };
}


#endif //EZTPLIB_RACE_HPP
