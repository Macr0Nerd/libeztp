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

int armor::save(const std::string &file) {
    std::ofstream out;
    out.open(file);

    if (out.good()) {
        std::string delim = "$";

        for (auto const &[key, arm] : armors) {
            out << key << delim;
            out << arm.name << delim;
            out << arm.baseAC << delim;
            out << arm.dexMax << delim;
            out << arm.armType << delim;
            out << arm.disadvantage << delim;
            out << arm.don << delim;
            out << arm.doff << delim;
            out << arm.strength << std::endl;
        }

        out << armors.size();
        out << "fin";

        out.flush();
        out.close();

        std::cout << "WRITTEN" << std::endl;
        return 1;
    } else {
        out.flush();
        out.close();

        std::cerr << "CAN'T WRITE" << std::endl;
        return 0;
    }
}

int armor::load(const std::string &file) {
    std::ifstream fin;
    fin.open(file);

    if (fin.good()) {
        std::string tmp;
        std::string token;
        std::string delim = "$";
        size_t pos;
        std::vector<std::string> mapper;

        armors.clear();

        while (getline(fin, tmp)) {
            if (tmp.substr(tmp.size() - 3, 3) == "fin") {
                if (armors.size() != std::stoi(tmp.substr(0, tmp.size() - 3))) {
                    fin.close();

                    std::cerr << "ERROR WHEN READING" << std::endl;
                    return 0;
                } else {
                    break;
                }
            }

            mapper.clear();
            while ((pos = tmp.find(delim)) != std::string::npos) {
                token = tmp.substr(0, pos);
                mapper.push_back(token);
                tmp.erase(0, pos + delim.size());
            }
            mapper.push_back(tmp);

            armors[mapper[0]] = {mapper[1],
                                 static_cast<unsigned short>(std::stoi(mapper[2])),
                                 static_cast<unsigned short>(std::stoi(mapper[3])),
                                 mapper[4][0],
                                 static_cast<bool>(std::stoi(mapper[5])),
                                 static_cast<unsigned short>(std::stoi(mapper[6])),
                                 static_cast<unsigned short>(std::stoi(mapper[7])),
                                 static_cast<unsigned short>(std::stoi(mapper[8]))
            };

            tmp.clear();
        }

        fin.close();

        std::cout << "READ" << std::endl;
        return 1;
    } else {
        fin.close();

        std::cerr << "CAN'T READ" << std::endl;
        return 0;
    }
}