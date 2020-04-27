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
add_library(LibEZTP::libeztp ALIAS libeztp)

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


##########################
# Installing the library #
##########################

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/LibEZTP)

install(TARGETS libeztp
        EXPORT libeztp-targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

set_target_properties(libeztp PROPERTIES EXPORT_NAME LibEZTP)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(EXPORT libeztp-targets
        FILE
            LibEZTPTargets.cmake
        NAMESPACE
            LibEZTP::
        DESTINATION
            ${INSTALL_CONFIGDIR}
        )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/LibEZTPConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/LibEZTPConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/LibEZTPConfig.cmake
        INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
        )

install(FILES
        ${CMAKE_CURRENT_LIST_DIR}/cmake/FindLibEZTP.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LibEZTPConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LibEZTPConfigVersion.cmake
        DESTINATION ${INSTALL_CONFIGDIR}
        )

configure_file(${CMAKE_CURRENT_LIST_DIR}/cmake/FindLibEZTP.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/FindLibEZTP.cmake
        COPYONLY)

export(EXPORT libeztp-targets
        FILE ${CMAKE_CURRENT_BINARY_DIR}/LibEZTPTargets.cmake
        NAMESPACE LibEZTP::)

export(PACKAGE LibEZTP)


#######################################
# This is to add the testing stuff in #
#######################################

add_subdirectory(test)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ext)