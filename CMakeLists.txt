cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(eztp VERSION 1.2.1 LANGUAGES CXX)


#########################################
# This is to create the libeztp library #
#########################################

include(FetchContent)

if(UNIX AND NOT APPLE)
    set(FETCHCONTENT_BASE_DIR $ENV{HOME}/.cache/ CACHE PATH "" FORCE)
endif()

if(WIN32)
    set(FETCHCONTENT_BASE_DIR "C:/Users/$ENV{USERNAME}/AppData/Local/Temp")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

if(APPLE)
    set(FETCHCONTENT_BASE_DIR $ENV{HOME}/Library/Caches CACHE PATH "" FORCE)
endif()

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.9.1
)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

option(PULL_DATA "Pull the API data from 5e API" OFF)

if(PULL_DATA)
    find_package(PythonInterp QUIET)

    if(PYTHON_FOUND AND EXISTS "${CMAKE_SOURCE_DIR}/data/apipull.py")
        execute_process(COMMAND ${PYTHON_EXECUTABLE} apipull.py
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/data/)
    endif()
endif()

add_library(libeztp SHARED src/libeztp.cpp)
add_library(LibEZTP::LibEZTP ALIAS libeztp)

set_target_properties(libeztp PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        PREFIX ""
)

#Adding the Headers in
target_include_directories(libeztp
        PUBLIC
            $<INSTALL_INTERFACE:include/>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(libeztp PUBLIC nlohmann_json::nlohmann_json)

target_compile_definitions(libeztp PUBLIC DATA_DIR="${CMAKE_SOURCE_DIR}/data/")

add_subdirectory(src)

add_executable(moola main.cpp)
target_link_libraries(moola LibEZTP::LibEZTP)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

##########################
# Installing the library #
##########################

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/LibEZTP)

install(TARGETS libeztp nlohmann_json
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
        FILE ${CMAKE_CURRENT_BINARY_DIR}/LibEZTPTargets.cmake
)

set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
export(PACKAGE LibEZTP)


#######################################
# This is to add the testing stuff in #
#######################################

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()