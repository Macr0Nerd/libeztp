#define CATCH_CONFIG_MAIN

#include <iostream>

#include "eztp/eztp.hpp"
#include "Catch2/catch.hpp"

TEST_CASE("Dice can roll within a range", "[dice]") {
    SECTION("Default Dice") {
        int x;

        SECTION("d0") {
            INFO("d0 Test Start");
            std::cout << "Starting d0 Tests..." << std::endl << std::flush;

            x = eztp::d0.roll();
            REQUIRE(x == 0);

            std::cout << "Passed d0" << std::endl << std::flush;
        }

        SECTION("d1") {
            INFO("d1 Test Start");
            std::cout << "Starting d1 Tests..." << std::endl << std::flush;

            x = eztp::d1.roll();
            REQUIRE(x == 1);

            std::cout << "Passed d1" << std::endl << std::flush;
        }

        SECTION("d2") {
            INFO("d2 Test Start");
            std::cout << "Starting d2 Tests..." << std::endl << std::flush;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d2 test " << i) {
                    INFO("d2 Test " + std::to_string(i) + " Start");

                    x = eztp::d2.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 2);
                }
            }

            std::cout << "Passed d2" << std::endl << std::flush;
        }

        SECTION("d4") {
            INFO("d4 Test Start");
            std::cout << "Starting d4 Tests..." << std::endl << std::flush;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d4 test " << i) {
                    INFO("d4 Test " + std::to_string(i) + " Start");

                    x = eztp::d4.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 4);
                }
            }

            std::cout << "Passed d4" << std::endl << std::flush;
        }

        SECTION("d6") {
            INFO("d6 Test Start");
            std::cout << "Starting d6 Tests..." << std::endl << std::flush;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d6 test " << i) {
                    INFO("d6 Test " + std::to_string(i) + " Start");

                    x = eztp::d6.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 6);
                }
            }

            std::cout << "Passed d6" << std::endl << std::flush;
        }

        SECTION("d8") {
            INFO("d8 Test Start");
            std::cout << "Starting d8 Tests..." << std::endl << std::flush;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d8 test" << i) {
                    INFO("d8 Test " + std::to_string(i) + " Start");

                    x = eztp::d8.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 8);
                }
            }

            std::cout << "Passed d8" << std::endl << std::flush;
        }

        SECTION("d10") {
            INFO("d10 Test Start");
            std::cout << "Starting d10 Tests..." << std::endl << std::flush;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d10 test" << i) {
                    INFO("d10 Test " + std::to_string(i) + " Start");

                    x = eztp::d10.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 10);
                }
            }

            std::cout << "Passed d10" << std::endl << std::flush;
        }

        SECTION("d12") {
            INFO("d12 Test Start");
            std::cout << "Starting d12 Tests..." << std::endl << std::flush;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d12 test" << i) {
                    INFO("d12 Test " + std::to_string(i) + " Start");

                    x = eztp::d12.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 12);
                }
            }

            std::cout << "Passed d12" << std::endl << std::flush;
        }

        SECTION("d20") {
            INFO("d20 Test Start");
            std::cout << "Starting d20 Tests..." << std::endl << std::flush;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d20 test" << i) {
                    INFO("d20 Test " + std::to_string(i) + " Start");

                    x = eztp::d20.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 20);
                }
            }

            std::cout << "Passed d20" << std::endl << std::flush;
        }

        SECTION("d100") {
            INFO("d100 Test Start");
            std::cout << "Starting d100 Tests..." << std::endl << std::flush;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d100 test" << i) {
                    INFO("d100 Test " + std::to_string(i) + " Start");

                    x = eztp::d100.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 100);
                }
            }

            std::cout << "Passed d100" << std::endl << std::flush;
        }

        std::cout << "Passed Default Dice" << std::endl << std::flush;
    }

    SECTION("Custom dice") {
        eztp::core::dice die = eztp::core::dice();

        SECTION("Default Case") {
            INFO("Default Test Start");
            std::cout << "Starting default case Tests..." << std::endl << std::flush;

            REQUIRE(die.roll() == -1);

            std::cout << "Passed default case" << std::endl << std::flush;
        }

        SECTION("Custom Case") {
            int x;

            INFO("Custom Case Start");
            std::cout << "Starting custom case Tests..." << std::endl << std::flush;

            die = eztp::core::dice(50);

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("Custom Test " << i) {
                    INFO("Custom Test " + std::to_string(i) + " Start");

                    x = die.roll();

                    CHECK(x >= 1);
                    CHECK(x <= 50);
                }
            }

            std::cout << "Passed Custom Case" << std::endl << std::flush;
        }

        SECTION("Non-Natural Case") {
            die = eztp::core::dice(-10);

            INFO("Non-natural Test Start");
            std::cout << "Starting non-natural case Tests..." << std::endl << std::flush;

            CHECK(die.roll() == -10);

            std::cout << "Passed non-natural case" << std::endl << std::flush;
        }

        std::cout << "Passed Custom Dice" << std::endl << std::flush;
    }
}

