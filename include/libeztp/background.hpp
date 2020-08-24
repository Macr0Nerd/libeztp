#pragma once

#ifndef LIBEZTP_BACKGROUND_HPP
#define LIBEZTP_BACKGROUND_HPP

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

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

        [[nodiscard]] static BackgroundStruct getBg(const std::string &name);

        [[nodiscard]] static std::map<std::string, BackgroundStruct> getBgs();

        [[nodiscard]] static bool save(const std::string& filename = "background.json");

        [[nodiscard]] static bool load(const std::string& filename = "background.json");
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Background::BackgroundStruct, name, gp, prof, equip)
}


#endif //LIBEZTP_BACKGROUND_HPP
