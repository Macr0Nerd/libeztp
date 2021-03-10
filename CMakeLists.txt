cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(eztp VERSION 1.1.0 LANGUAGES CXX)


option(BUILD_TESTING "This is to build the tests" ON)


#########################################
# This is to create the libeztp library #
#########################################

include(FetchContent)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent.git
        GIT_TAG v3.9.1
)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_library(libeztp SHARED src/libeztp.cpp)
add_library(LibEZTP::libeztp ALIAS libeztp)

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

target_link_libraries(libeztp PRIVATE nlohmann_json::nlohmann_json)

add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

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

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()