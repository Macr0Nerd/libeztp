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