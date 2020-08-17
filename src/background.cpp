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

namespace {
    std::map<std::string, eztp::Background::BackgroundStruct> bgs = {
            {"ACOLYTE", {"ACOLYTE", 15, {"INSIGHT", "RELIGION"},
                                {"Holy Symbol", "Prayer Book", "5 sticks of incense", "vestments", "set of common clothes"}}}
    };
}

void eztp::Background::addBg(const std::string &name, BackgroundStruct &stats) {
    ::bgs[name] = stats;
}

void eztp::Background::delBg(const std::string &name) {
    ::bgs.erase(name);
}

eztp::Background::BackgroundStruct eztp::Background::getBg(const std::string &name) {
    return ::bgs.at(name);
}

bool eztp::Background::save(const std::string &filename) {
    std::ofstream out(filename);

    if (out.good()) {
        try {
            nlohmann::json js(::bgs);

            out << js << std::endl;

            out.close();

            return true;
        } catch (...) {
            out.close();
            return false;
        }
    } else {
        out.close();
        return false;
    }
}

bool eztp::Background::load(const std::string &filename) {
    std::ifstream in(filename);

    if (in.good()) {
        try {
            nlohmann::json js, tmp;
            in >> js;
            ::bgs.clear();
            ::bgs = js.get<std::map<std::string, BackgroundStruct>>();

            in.close();
            return true;
        } catch (...) {
            in.close();
            return false;
        }
    } else {
        in.close();
        return false;
    }
}