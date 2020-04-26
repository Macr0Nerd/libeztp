cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(eztp CXX)

#All the basic requirements and shizz
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CSS_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Necessary directories to function
set(LIB_DIR lib)
include_directories(${LIB_DIR})

set(SRC_DIR include)
include_directories(${SRC_DIR})

#Main library files
set(SRC_FILES
	${SRC_DIR}/eztp.hpp
        ${SRC_DIR}/eztp/dice.hpp ${SRC_DIR}/eztp/dice.cpp
        ${SRC_DIR}/eztp/weapons.hpp ${SRC_DIR}/eztp/weapons.cpp
        ${SRC_DIR}/eztp/armor.hpp ${SRC_DIR}/eztp/armor.cpp
        ${SRC_DIR}/eztp/race.hpp ${SRC_DIR}/eztp/race.cpp
        ${SRC_DIR}/eztp/background.hpp ${SRC_DIR}/eztp/background.cpp
        ${SRC_DIR}/eztp/character.hpp ${SRC_DIR}/eztp/character.cpp)

add_library(${PROJECT_NAME} ${SRC_FILES})

set(TST_DIR test)
set(TST_FILES
        ${TST_DIR}/baseTests.cpp)

add_executable(${PROJECT_NAME}_test ${TST_FILES})
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})
