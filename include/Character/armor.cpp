#include "armor.hpp"

using namespace eztp::character;

armor::amap armor::armors = {
        {"UNARMORED",       {"UNARMORED",       10, 10, 'N', false, 0,  0, 0}},
        {"PADDED",          {"PADDED",          11, 10, 'L', true,  1,  1, 0}},
        {"LEATHER",         {"LEATHER",         11, 10, 'L', false, 1,  1, 0}},
        {"STUDDED LEATHER", {"STUDDED LEATHER", 12, 10, 'L', false, 1,  1, 0}},
        {"HIDE",            {"HIDE",            12, 2,  'M', false, 5,  1, 0}},
        {"CHAIN SHIRT",     {"CHAIN SHIRT",     13, 2,  'M', false, 5,  1, 0}},
        {"SCALE MAIL",      {"SCALE MAIL",      14, 2,  'M', true,  5,  1, 0}},
        {"BREASTPLATE",     {"BREASTPLATE",     14, 2,  'M', false, 5,  1, 0}},
        {"HALF PLATE",      {"HALF PLATE",      15, 2,  'M', true,  5,  1, 0}},
        {"RING MAIL",       {"RING MAIL",       14, 0,  'H', true,  10, 5, 0}},
        {"CHAIN MAIL",      {"CHAIN MAIL",      16, 0,  'H', true,  10, 1, 13}},
        {"SPLINT",          {"SPLINT",          17, 0,  'H', true,  10, 5, 15}},
        {"PLATE",           {"PLATE",           18, 0,  'H', true,  10, 5, 15}}
};

void armor::addArmor(const std::string &name, Armor &stats) {
    armors[name] = stats;
}

void armor::delArmor(const std::string &name) {
    armors.erase(name);
}