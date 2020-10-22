#pragma once

#ifndef LIBEZTP_BACKGROUND_HPP
#define LIBEZTP_BACKGROUND_HPP

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

namespace eztp::Background {
    struct BackgroundStruct {
        std::string name;
        int gp;

        std::vector<std::string> prof;
        std::vector<std::string> equip;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(BackgroundStruct, name, gp, prof, equip)
    };

    void addBg(const std::string &name, BackgroundStruct &stats);

    void delBg(const std::string &name);

    [[nodiscard]] BackgroundStruct getBg(const std::string &name);

    [[nodiscard]] std::map<std::string, BackgroundStruct> getBgs();

    [[nodiscard]] bool save(const std::string &filename = "background.json");

    [[nodiscard]] bool load(const std::string &filename = "background.json");
}


#endif //LIBEZTP_BACKGROUND_HPP
