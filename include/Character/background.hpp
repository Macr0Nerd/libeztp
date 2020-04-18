#pragma once

#ifndef EZTPLIB_BACKGROUND_HPP
#define EZTPLIB_BACKGROUND_HPP

#include <string>
#include <map>
#include <vector>

namespace eztp::character {
    class background {
    public:
        struct Background {
            int gp;

            std::vector<std::string> prof;
            std::vector<std::string> equip;
        };

        typedef std::map<std::string, Background> bmap;
        static bmap bgs;

        background() = default;

        ~background() = default;

        static void add_bg(const std::string &name, Background &stats);

        static void del_bg(const std::string &name);
    };
}


#endif //EZTPLIB_BACKGROUND_HPP
