/*
 *  Copyright (C) 2020  Gabriele A. Ron
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "libeztp/background.hpp"

using namespace eztp;

background::bmap background::bgs = {
        {"ACOLYTE", {"ACOLYTE", 15, {"INSIGHT", "RELIGION"},
                            {"Holy Symbol", "Prayer Book", "5 sticks of incense", "vestments", "set of common clothes"}}}
};

void background::addBg(const std::string &name, Background &stats) {
    bgs[name] = stats;
}

void background::delBg(const std::string &name) {
    bgs.erase(name);
}

int background::save(const std::string &file) {
    std::ofstream out;
    out.open(file);

    if (out.good()) {
        std::string delim = "$";
        std::string delim2 = "|";

        for (auto const &[key, bg] : bgs) {
            out << key << delim;
            out << bg.name << delim;
            out << bg.gp << delim;

            for (int i = 0; i < bg.prof.size(); ++i) {
                out << bg.prof[i];

                if (i != bg.prof.size() - 1) {
                    out << delim2;
                }
            }
            out << delim;

            for (int j = 0; j < bg.equip.size(); ++j) {
                out << bg.equip[j];

                if (j != bg.equip.size() - 1) {
                    out << delim2;
                }
            }
            out << std::endl;
        }

        out << bgs.size();
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

int background::load(const std::string &file) {
    std::ifstream fin;
    fin.open(file);

    if (fin.good()) {
        std::string tmp;
        std::string token;
        std::string delim = "$";
        std::string delim2 = "|";
        size_t pos;
        std::vector<std::string> mapper, p, e;

        while (getline(fin, tmp)) {
            if (tmp.substr(tmp.size() - 3, 3) == "fin") {
                if (bgs.size() != std::stoi(tmp.substr(0, tmp.size() - 3))) {
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

            p.clear();
            while ((pos = mapper[3].find(delim2)) != std::string::npos) {
                token = mapper[3].substr(0, pos);
                p.push_back(token);
                mapper[3].erase(0, pos + delim2.size());
            }
            p.push_back(mapper[3]);

            e.clear();
            while ((pos = mapper[4].find(delim2)) != std::string::npos) {
                token = mapper[4].substr(0, pos);
                e.push_back(token);
                mapper[4].erase(0, pos + delim2.size());
            }
            e.push_back(mapper[4]);

            bgs[mapper[0]] = {
                    mapper[1],
                    std::stoi(mapper[2]),
                    p,
                    e
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