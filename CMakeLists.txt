cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(eztp VERSION 1.4.0 LANGUAGES CXX)


#######################################################
# This is used to set just some basic stuff for CMake #
#######################################################

set(CMAKE_CXX_STANDARD 17) #TODO: Use target_compile_options instead
set(CMAKE_CSS_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


#########################################
# This is to create the libeztp library #
#########################################

find_package(nlohmann_json 3.2.0 REQUIRED)

add_library(libeztp SHARED src/libeztp.cpp)
add_library(LibEZTP::libeztp ALIAS libeztp)

target_link_libraries(libeztp PRIVATE nlohmann_json::nlohmann_json)

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
            ${CMAKE_CURRENT_SOURCE_DIR}/src/creature.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/character.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/dice.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/race.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/weapons.cpp
        )

#It's called "libeztp" I don't need CMake putting out "liblibeztp.so"
SET_TARGET_PROPERTIES(libeztp PROPERTIES PREFIX "")


##########################
# Installing the library #
##########################

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/LibEZTP)

install(TARGETS libeztp
        EXPORT libeztp-targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/LibEZTPConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)

set_target_properties(libeztp PROPERTIES EXPORT_NAME LibEZTP)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT libeztp-targets
        FILE
            LibEZTPConfig.cmake
        NAMESPACE
            LibEZTP::
        DESTINATION ${INSTALL_CONFIGDIR}
        )

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/LibEZTPConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LibEZTPConfigVersion.cmake
        DESTINATION ${INSTALL_CONFIGDIR}
        )

export(
        EXPORT libeztp-targets
        NAMESPACE LibEZTP::
        FILE ${CMAKE_CURRENT_BINARY_DIR}/LibEZTPConfig.cmake
        )

set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
export(PACKAGE LibEZTP)


#######################################
# This is to add the testing stuff in #
#######################################

add_subdirectory(test)
target_include_directories(test
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/ext
        )