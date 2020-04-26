cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(eztp VERSION 1.3.1 LANGUAGES CXX)


#######################################################
# This is used to set just some basic stuff for CMake #
#######################################################

set(CMAKE_CXX_STANDARD 17) #TODO: Use target_compile_options instead
set(CMAKE_CSS_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


#########################################
# This is to create the libeztp library #
#########################################

add_library(libeztp SHARED src/libeztp.cpp)
add_library(EZTP::LibEZTP ALIAS libeztp)

#Adding the Headers in
target_include_directories(libeztp
        PUBLIC
            $<INSTALL_INTERFACE:include/>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

#Adding in the source files
target_sources(libeztp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/armor.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/background.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/character.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/dice.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/race.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/weapons.cpp
        )

#It's called "libeztp" I don't need CMake putting out "liblibeztp.so"
SET_TARGET_PROPERTIES(libeztp PROPERTIES PREFIX "")


#######################################
# This is to add the testing stuff in #
#######################################

add_subdirectory(test)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ext)