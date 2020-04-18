cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(eztplib CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CSS_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR include)
include_directories(${SRC_DIR})

set(SRC_FILES
        ${SRC_DIR}/eztp.hpp
        ${SRC_DIR}/Core/dice.hpp ${SRC_DIR}/Core/dice.cpp
        ${SRC_DIR}/Character/weapons.hpp ${SRC_DIR}/Character/weapons.cpp
        ${SRC_DIR}/Character/armor.hpp ${SRC_DIR}/Character/armor.cpp
        ${SRC_DIR}/Character/race.hpp ${SRC_DIR}/Character/race.cpp
        ${SRC_DIR}/Character/background.hpp ${SRC_DIR}/Character/background.cpp
        ${SRC_DIR}/Character/character.hpp ${SRC_DIR}/Character/character.cpp)

add_library(eztplib ${SRC_FILES})