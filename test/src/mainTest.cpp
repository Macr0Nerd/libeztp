#define CATCH_CONFIG_MAIN

#include <iostream>

#include "libeztp/libeztp.hpp"
#include "Catch2/catch.hpp"

TEST_CASE("Dice can roll within a range", "[dice]") {
    SECTION("Default Dice") {
        int x;

        SECTION("d0") {
            INFO("d0 Test Start");
            std::cout << "Starting d0 Tests..." << std::endl;

            x = eztp::d0.roll();
            REQUIRE(x == 0);

            std::cout << "Passed d0" << std::endl;
        }

        SECTION("d1") {
            INFO("d1 Test Start");
            std::cout << "Starting d1 Tests..." << std::endl;

            x = eztp::d1.roll();
            REQUIRE(x == 1);

            std::cout << "Passed d1" << std::endl;
        }

        SECTION("d2") {
            INFO("d2 Test Start");
            std::cout << "Starting d2 Tests..." << std::endl;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d2 test " << i) {
                    INFO("d2 Test " + std::to_string(i) + " Start");

                    x = eztp::d2.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 2);
                }
            }

            std::cout << "Passed d2" << std::endl;
        }

        SECTION("d4") {
            INFO("d4 Test Start");
            std::cout << "Starting d4 Tests..." << std::endl;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d4 test " << i) {
                    INFO("d4 Test " + std::to_string(i) + " Start");

                    x = eztp::d4.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 4);
                }
            }

            std::cout << "Passed d4" << std::endl;
        }

        SECTION("d6") {
            INFO("d6 Test Start");
            std::cout << "Starting d6 Tests..." << std::endl;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d6 test " << i) {
                    INFO("d6 Test " + std::to_string(i) + " Start");

                    x = eztp::d6.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 6);
                }
            }

            std::cout << "Passed d6" << std::endl;
        }

        SECTION("d8") {
            INFO("d8 Test Start");
            std::cout << "Starting d8 Tests..." << std::endl;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d8 test" << i) {
                    INFO("d8 Test " + std::to_string(i) + " Start");

                    x = eztp::d8.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 8);
                }
            }

            std::cout << "Passed d8" << std::endl;
        }

        SECTION("d10") {
            INFO("d10 Test Start");
            std::cout << "Starting d10 Tests..." << std::endl;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d10 test" << i) {
                    INFO("d10 Test " + std::to_string(i) + " Start");

                    x = eztp::d10.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 10);
                }
            }

            std::cout << "Passed d10" << std::endl;
        }

        SECTION("d12") {
            INFO("d12 Test Start");
            std::cout << "Starting d12 Tests..." << std::endl;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d12 test" << i) {
                    INFO("d12 Test " + std::to_string(i) + " Start");

                    x = eztp::d12.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 12);
                }
            }

            std::cout << "Passed d12" << std::endl;
        }

        SECTION("d20") {
            INFO("d20 Test Start");
            std::cout << "Starting d20 Tests..." << std::endl;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d20 test" << i) {
                    INFO("d20 Test " + std::to_string(i) + " Start");

                    x = eztp::d20.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 20);
                }
            }

            std::cout << "Passed d20" << std::endl;
        }

        SECTION("d100") {
            INFO("d100 Test Start");
            std::cout << "Starting d100 Tests..." << std::endl;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d100 test" << i) {
                    INFO("d100 Test " + std::to_string(i) + " Start");

                    x = eztp::d100.roll();
                    CHECK(x >= 1);
                    CHECK(x <= 100);
                }
            }

            std::cout << "Passed d100" << std::endl;
        }

        std::cout << "Passed Default Dice" << std::endl;
    }

    SECTION("Custom dice") {
        eztp::dice die = eztp::dice();

        SECTION("Default Case") {
            INFO("Default Test Start");
            std::cout << "Starting default case Tests..." << std::endl;

            REQUIRE(die.roll() == -1);

            std::cout << "Passed default case" << std::endl;
        }

        SECTION("Custom Case") {
            int x;

            INFO("Custom Case Start");
            std::cout << "Starting custom case Tests..." << std::endl;

            die = eztp::dice(50);

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("Custom Test " << i) {
                    INFO("Custom Test " + std::to_string(i) + " Start");

                    x = die.roll();

                    CHECK(x >= 1);
                    CHECK(x <= 50);
                }
            }

            std::cout << "Passed Custom Case" << std::endl;
        }

        SECTION("Non-Natural Case") {
            die = eztp::dice(-10);

            INFO("Non-natural Test Start");
            std::cout << "Starting non-natural case Tests..." << std::endl;

            CHECK(die.roll() == -10);

            std::cout << "Passed non-natural case" << std::endl;
        }

        std::cout << "Passed Custom Dice" << std::endl;
    }
}

TEST_CASE("Weapons data is accessible", "[weapons]") {
    SECTION("Dice check") {
        INFO("Dice tests starting");
        std::cout << "Starting weapons/dice Tests..." << std::endl;

        CHECK(eztp::weapons::weaps["DAGGER"].die == eztp::d4);
        CHECK(eztp::weapons::weaps["SHORTBOW"].die == eztp::d6);
        CHECK(eztp::weapons::weaps["LONGSWORD+"].die == eztp::d10);
        CHECK(eztp::weapons::weaps["LONGBOW"].die == eztp::d8);

        std::cout << "Passed dice tests" << std::endl;
    }

    SECTION("Ability check") {
        INFO("Ability tests starting");
        std::cout << "Starting weapons/ability Tests..." << std::endl;

        CHECK(eztp::weapons::weaps["DAGGER"].ability == 3);
        CHECK(eztp::weapons::weaps["SHORTBOW"].ability == 2);
        CHECK(eztp::weapons::weaps["LONGSWORD+"].ability == 1);
        CHECK(eztp::weapons::weaps["LONGBOW"].ability == 2);

        std::cout << "Passed ability tests" << std::endl;
    }

    SECTION("Martial Check") {
        INFO("Martial tests starting");
        std::cout << "Starting weapons/martial Tests..." << std::endl;

        CHECK_FALSE(eztp::weapons::weaps["DAGGER"].martial);
        CHECK_FALSE(eztp::weapons::weaps["SHORTBOW"].martial);
        CHECK(eztp::weapons::weaps["LONGSWORD+"].martial);
        CHECK(eztp::weapons::weaps["LONGBOW"].martial);

        std::cout << "Passed martial tests" << std::endl;
    }

    SECTION("Range Check") {
        INFO("Range tests starting");
        std::cout << "Starting weapons/range Tests..." << std::endl;

        CHECK(eztp::weapons::weaps["DAGGER"].ranged == 2);
        CHECK(eztp::weapons::weaps["DAGGER"].range.first == 20);
        CHECK(eztp::weapons::weaps["DAGGER"].range.second == 60);

        CHECK(eztp::weapons::weaps["SHORTBOW"].ranged == 1);
        CHECK(eztp::weapons::weaps["SHORTBOW"].range.first == 80);
        CHECK(eztp::weapons::weaps["SHORTBOW"].range.second == 320);

        CHECK(eztp::weapons::weaps["GLAIVE"].ranged == 4);
        CHECK(eztp::weapons::weaps["GLAIVE"].range.first == 0);
        CHECK(eztp::weapons::weaps["GLAIVE"].range.second == 0);

        CHECK(eztp::weapons::weaps["NET"].ranged == 3);
        CHECK(eztp::weapons::weaps["NET"].range.first == 5);
        CHECK(eztp::weapons::weaps["NET"].range.second == 15);

        std::cout << "Passed range tests" << std::endl;
    }
}

TEST_CASE("Armor data is accessible", "[armor]") {
    SECTION("Base AC") {
        INFO("Base AC Tests");
        std::cout << "Starting armor/ac Tests..." << std::endl;

        CHECK(eztp::armor::armors["LEATHER"].baseAC == 11);
        CHECK(eztp::armor::armors["BREASTPLATE"].baseAC == 14);
        CHECK(eztp::armor::armors["PLATE"].baseAC == 18);

        std::cout << "Passed base AC" << std::endl;
    }

    SECTION("Armor type") {
        INFO("Armor Type Tests");
        std::cout << "Starting armor/type Tests..." << std::endl;

        CHECK(eztp::armor::armors["LEATHER"].armType == 'L');
        CHECK(eztp::armor::armors["BREASTPLATE"].armType == 'M');
        CHECK(eztp::armor::armors["PLATE"].armType == 'H');

        std::cout << "Passed armor type" << std::endl;
    }

    SECTION("Stealth") {
        INFO("Stealth Tests");
        std::cout << "Starting armor/stealth Tests..." << std::endl;

        CHECK_FALSE(eztp::armor::armors["LEATHER"].disadvantage);
        CHECK_FALSE(eztp::armor::armors["BREASTPLATE"].disadvantage);
        CHECK(eztp::armor::armors["PLATE"].disadvantage);

        std::cout << "Passes stealth tests" << std::endl;
    }
}

TEST_CASE("Race data is accessible", "[races") {
    SECTION("Abilities/Boosts") {
        INFO("Abilities/Boosts Tests");
        std::cout << "Starting abilities/boosts Tests..." << std::endl;

        CHECK(eztp::race::races["HILL DWARF"].abis[1] == "WIS");
        CHECK(eztp::race::races["HILL DWARF"].boosts[1] == 1);

        CHECK(eztp::race::races["HIGH ELF"].abis[0] == "DEX");
        CHECK(eztp::race::races["HIGH ELF"].boosts[0] == 2);

        CHECK(eztp::race::races["TIEFLING"].abis[1] == "CHA");
        CHECK(eztp::race::races["TIEFLING"].boosts[1] == 2);

        std::cout << "Passed abilities/boosts tests" << std::endl;
    }

    SECTION("Size") {
        INFO("Size Tests");
        std::cout << "Starting size Tests..." << std::endl;

        CHECK(eztp::race::races["HALF-ORC"].size == 'M');
        CHECK(eztp::race::races["LIGHTFOOT HALFLING"].size == 'S');
        CHECK(eztp::race::races["HUMAN"].size == 'M');

        std::cout << "Passed size tests" << std::endl;
    }

    SECTION("Speed") {
        INFO("Speed Tests");
        std::cout << "Starting speed Tests..." << std::endl;

        CHECK(eztp::race::races["HALF-ELF"].speed == 30);
        CHECK(eztp::race::races["HILL DWARF"].speed == 25);
        CHECK(eztp::race::races["HUMAN"].speed == 30);

        std::cout << "Passed speed tests" << std::endl;
    }
}

TEST_CASE("Background data is accessible", "[background]") {
    SECTION("gp") {
        INFO("gp Tests");
        std::cout << "Starting gp Tests..." << std::endl;

        CHECK(eztp::background::bgs["ACOLYTE"].gp == 15);

        std::cout << "Passed gp tests" << std::endl;
    }

    SECTION("Proficiencies") {
        INFO("Proficiencies Tests");
        std::cout << "Starting proficiencies Tests..." << std::endl;

        CHECK(eztp::background::bgs["ACOLYTE"].prof[1] == "RELIGION");

        std::cout << "Passed proficiencies tests" << std::endl;
    }

    SECTION("Equipment") {
        INFO("Equipment Tests");
        std::cout << "Starting equipment Tests..." << std::endl;

        CHECK(eztp::background::bgs["ACOLYTE"].equip[0] == "Holy Symbol");

        std::cout << "Passed equipment tests" << std::endl;
    }
}
