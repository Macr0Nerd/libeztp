cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(eztplib CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CSS_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR include)
include_directories(${SRC_DIR})

set(SRC_FILES
        ${SRC_DIR}/eztp/eztp.hpp
        ${SRC_DIR}/eztp/Core/dice.hpp ${SRC_DIR}/eztp/Core/dice.cpp
        ${SRC_DIR}/eztp/Character/weapons.hpp ${SRC_DIR}/eztp/Character/weapons.cpp
        ${SRC_DIR}/eztp/Character/armor.hpp ${SRC_DIR}/eztp/Character/armor.cpp
        ${SRC_DIR}/eztp/Character/race.hpp ${SRC_DIR}/eztp/Character/race.cpp
        ${SRC_DIR}/eztp/Character/background.hpp ${SRC_DIR}/eztp/Character/background.cpp
        ${SRC_DIR}/eztp/Character/character.hpp ${SRC_DIR}/eztp/Character/character.cpp)

add_library(eztplib ${SRC_FILES})