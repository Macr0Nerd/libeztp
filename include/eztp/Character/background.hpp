#pragma once

#ifndef EZTPLIB_BACKGROUND_HPP
#define EZTPLIB_BACKGROUND_HPP

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>

namespace eztp::character {
    class background {
    public:
        struct Background {
            std::string name;
            int gp;

            std::vector<std::string> prof;
            std::vector<std::string> equip;
        };

        typedef std::map<std::string, Background> bmap;
        static bmap bgs;

        background() = default;

        ~background() = default;

        static void addBg(const std::string &name, Background &stats);

        static void delBg(const std::string &name);

        static int save(const std::string &file);

        static int load(const std::string &file);
    };
}


#endif //EZTPLIB_BACKGROUND_HPP
