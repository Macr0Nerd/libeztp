#pragma once

#ifndef LIBEZTP_BACKGROUND_HPP
#define LIBEZTP_BACKGROUND_HPP

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>

namespace eztp {
    class Background {
    public:
        struct BackgroundStruct {
            std::string name;
            int gp;

            std::vector<std::string> prof;
            std::vector<std::string> equip;
        };

        Background() = default;

        ~Background() = default;

        static void addBg(const std::string &name, BackgroundStruct &stats);

        static void delBg(const std::string &name);

        static BackgroundStruct getBg(const std::string &name);
    };
}


#endif //LIBEZTP_BACKGROUND_HPP
