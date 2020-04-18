#include "background.hpp"

using namespace eztp::character;

background::bmap background::bgs = {
        {"ACOLYTE", {15, {"INSIGHT", "RELIGION"},
                     {"Holy Symbol", "Prayer Book", "5 sticks of incense", "vestments", "set of common clothes"}}}
};

void background::addBg(const std::string &name, Background &stats) {
    bgs[name] = stats;
}

void background::delBg(const std::string &name) {
    bgs.erase(name);
}