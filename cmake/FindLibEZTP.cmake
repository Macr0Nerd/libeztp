# FindLibEZTP.cmake
#
# Finds the EZTP library
#
# This will define the following variables
#
#    LibEZTP_FOUND
#    LibEZTP_LIBRARY
#    LibEZTP_INCLUDE_DIRS
#
# and the following imported targets
#
#    EZTP::LibEZTP
#
# Author: Gabriele A. Ron - macrocode@yahoo.com

find_package(PkgConfig)
pkg_check_modules(PC_LibEZTP QUIET LibEZTP)

find_path(LibEZTP_INCLUDE_DIR
        NAMES libeztp.hpp
        PATHS ${PC_LibEZTP_INCLUDE_DIRS}
        PATH_SUFFIXES libeztp
        )

find_library(LibEZTP_LIBRARY
        NAMES libeztp eztplib eztp
        PATHS ${PC_LibEZTP_LIBRARY_DIRS}
        )

set(LibEZTP_VERSION ${PC_LibEZTP})

mark_as_advanced(LibEZTP_FOUND LibEZTP_INCLUDE_DIR LibEZTP_LIBRARY)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Foo
        FOUND_VAR LibEZTP_FOUND
        REQUIRED_VARS
        LibEZTP_LIBRARY
        LibEZTP_INCLUDE_DIR
        VERSION_VAR LibEZTP_VERSION
        )

if(LibEZTP_FOUND)
    set(LibEZTP_LIBRARIES ${LibEZTP_LIBRARY})
    set(LibEZTP_INCLUDE_DIRS ${LibEZTP_INCLUDE_DIR})
endif()

if(LibEZTP_FOUND AND NOT TARGET EZTP::LibEZTP)
    add_library(EZTP::LibEZTP UNKNOWN IMPORTED)
    set_target_properties(EZTP::LibEZTP PROPERTIES
            IMPORTED_LOCATION "${LibEZTP_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${LibEZTP_INCLUDE_DIR}")
endif()