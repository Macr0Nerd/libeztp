cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(eztp VERSION 1.3.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) #I'll use target_compile_options when I'm not running on 0 hours of sleep
set(CMAKE_CSS_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(libeztp SHARED src/libeztp.cpp)

target_include_directories(libeztp
        PUBLIC
            $<INSTALL_INTERFACE:include/>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_sources(libeztp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/armor.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/background.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/character.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/dice.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/race.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/weapons.cpp
)

SET_TARGET_PROPERTIES(libeztp PROPERTIES PREFIX "")

add_subdirectory(test)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ext)