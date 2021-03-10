FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG v2.13.4
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests mainTest.cpp)

set_target_properties(tests PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

target_link_libraries(tests PRIVATE LibEZTP::libeztp)
target_link_libraries(tests PRIVATE Catch2::Catch2)
target_link_libraries(tests PRIVATE nlohmann_json::nlohmann_json)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)

include(ParseAndAddCatchTests)
ParseAndAddCatchTests(tests)