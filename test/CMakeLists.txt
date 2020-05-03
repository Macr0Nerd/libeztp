find_package(LibEZTP)

add_executable(test src/mainTest.cpp)
target_link_libraries(test PRIVATE LibEZTP::LibEZTP)