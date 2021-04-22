#define CATCH_CONFIG_MAIN

#include <iostream>
#include <catch2/catch.hpp>

#include "libeztp/libeztp.hpp"

TEST_CASE("Dice can roll within a range", "[dice]") {
    SECTION("Default Dice") {
        int x;

        SECTION("d0") {
            INFO("d0 Test Start");
            std::cout << "Starting d0 Tests..." << std::endl;

            x = eztp::dice.at(0).roll();
            REQUIRE(x == 0);

            std::cout << "Passed d0" << std::endl;
        }

        SECTION("d1") {
            INFO("d1 Test Start");
            std::cout << "Starting d1 Tests..." << std::endl;

            x = eztp::dice.at(1).roll();
            REQUIRE(x == 1);

            std::cout << "Passed d1" << std::endl;
        }

        SECTION("d2") {
            INFO("d2 Test Start");
            std::cout << "Starting d2 Tests..." << std::endl;

            for (int i = 0; i < 5; ++i) {
                DYNAMIC_SECTION("d2 tests " << i) {
                    INFO("d2 Test " + std::to_string(i) + " Start");

                    x = eztp::dice.at(2).roll();
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
                DYNAMIC_SECTION("d4 tests " << i) {
                    INFO("d4 Test " + std::to_string(i) + " Start");

                    x = eztp::dice.at(4).roll();
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
                DYNAMIC_SECTION("d6 tests " << i) {
                    INFO("d6 Test " + std::to_string(i) + " Start");

                    x = eztp::dice.at(6).roll();
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
                DYNAMIC_SECTION("d8 tests" << i) {
                    INFO("d8 Test " + std::to_string(i) + " Start");

                    x = eztp::dice.at(8).roll();
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
                DYNAMIC_SECTION("d10 tests" << i) {
                    INFO("d10 Test " + std::to_string(i) + " Start");

                    x = eztp::dice.at(10).roll();
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
                DYNAMIC_SECTION("d12 tests" << i) {
                    INFO("d12 Test " + std::to_string(i) + " Start");

                    x = eztp::dice.at(12).roll();
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
                DYNAMIC_SECTION("d20 tests" << i) {
                    INFO("d20 Test " + std::to_string(i) + " Start");

                    x = eztp::dice.at(20).roll();
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
                DYNAMIC_SECTION("d100 tests" << i) {
                    INFO("d100 Test " + std::to_string(i) + " Start");

                    x = eztp::dice.at(100).roll();
                    CHECK(x >= 1);
                    CHECK(x <= 100);
                }
            }

            std::cout << "Passed d100" << std::endl;
        }

        std::cout << "Passed Default Dice" << std::endl;
    }

    SECTION("Custom dice") {
        eztp::Die die = eztp::Die();

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

            die = eztp::Die(50);

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
            die = eztp::Die(-10);

            INFO("Non-natural Test Start");
            std::cout << "Starting non-natural case Tests..." << std::endl;

            CHECK(die.roll() == -10);

            std::cout << "Passed non-natural case" << std::endl;
        }

        std::cout << "Passed Custom Dice" << std::endl;
    }
}

TEST_CASE("Weapons data is accessible", "[weapons]") {
    SECTION("Loading") {
        INFO("Load Tests");
        std::cout << "Starting weapons/load Tests" << std::endl;

        CHECK(eztp::Weapons::load());

        std::cout << "Passed load tests" << std::endl;
    }

    SECTION("Dice check") {
        INFO("Dice tests starting");
        std::cout << "Starting weapons/dice Tests..." << std::endl;

        CHECK(eztp::Weapons::getWeapon("dagger").die == eztp::dice.at(4));
        CHECK(eztp::Weapons::getWeapon("shortbow").die == eztp::dice.at(6));
        CHECK(eztp::Weapons::getWeapon("longsword+").die == eztp::dice.at(10));
        CHECK(eztp::Weapons::getWeapon("longbow").die == eztp::dice.at(8));

        std::cout << "Passed dice tests" << std::endl;
    }

    SECTION("Martial Check") {
        INFO("Martial tests starting");
        std::cout << "Starting weapons/martial Tests..." << std::endl;

        CHECK(eztp::Weapons::getWeapon("dagger").weapType == "Simple Melee");
        CHECK(eztp::Weapons::getWeapon("shortbow").weapType == "Simple Ranged");
        CHECK(eztp::Weapons::getWeapon("longsword+").weapType == "Martial Melee");
        CHECK(eztp::Weapons::getWeapon("longbow").weapType == "Martial Ranged");

        std::cout << "Passed martial tests" << std::endl;
    }

    SECTION("Range Check") {
        INFO("Range tests starting");
        std::cout << "Starting weapons/range Tests..." << std::endl;

        CHECK(eztp::Weapons::getWeapon("longsword+").range.first == 5);
        CHECK(eztp::Weapons::getWeapon("longsword+").range.second == 0);

        CHECK(eztp::Weapons::getWeapon("dagger*").range.first == 20);
        CHECK(eztp::Weapons::getWeapon("dagger*").range.second == 60);

        CHECK(eztp::Weapons::getWeapon("shortbow").range.first == 80);
        CHECK(eztp::Weapons::getWeapon("shortbow").range.second == 320);

        std::cout << "Passed range tests" << std::endl;
    }
}

TEST_CASE("Armor data is accessible", "[armor]") {
    SECTION("Loading") {
        INFO("Load Tests");
        std::cout << "Starting armor/load Tests" << std::endl;

        CHECK(eztp::Armor::load());

        std::cout << "Passed load tests" << std::endl;
    }

    SECTION("Base AC") {
        INFO("Base AC Tests");
        std::cout << "Starting armor/ac Tests..." << std::endl;

        CHECK(eztp::Armor::getArmor("leather").baseAC == 11);
        CHECK(eztp::Armor::getArmor("breastplate").baseAC == 14);
        CHECK(eztp::Armor::getArmor("plate").baseAC == 18);

        std::cout << "Passed base AC" << std::endl;
    }

    SECTION("Armor type") {
        INFO("Armor Type Tests");
        std::cout << "Starting armor/type Tests..." << std::endl;

        CHECK(eztp::Armor::getArmor("leather").armType == "Light");
        CHECK(eztp::Armor::getArmor("breastplate").armType == "Medium");
        CHECK(eztp::Armor::getArmor("plate").armType == "Heavy");

        std::cout << "Passed armor type" << std::endl;
    }

    SECTION("Stealth") {
        INFO("Stealth Tests");
        std::cout << "Starting armor/stealth Tests..." << std::endl;

        CHECK_FALSE(eztp::Armor::getArmor("leather").disadvantage);
        CHECK_FALSE(eztp::Armor::getArmor("breastplate").disadvantage);
        CHECK(eztp::Armor::getArmor("plate").disadvantage);

        std::cout << "Passed stealth tests" << std::endl;
    }
}

TEST_CASE("Race data is accessible", "[races]") {
    SECTION("Abilities/Boosts") {
        INFO("Abilities/Boosts Tests");
        std::cout << "Starting race/abilities/boosts Tests..." << std::endl;

        CHECK(eztp::Race::getRace("HILL DWARF").abis[1] == "WIS");
        CHECK(eztp::Race::getRace("HILL DWARF").boosts[1] == 1);

        CHECK(eztp::Race::getRace("HIGH ELF").abis[0] == "DEX");
        CHECK(eztp::Race::getRace("HIGH ELF").boosts[0] == 2);

        CHECK(eztp::Race::getRace("TIEFLING").abis[1] == "CHA");
        CHECK(eztp::Race::getRace("TIEFLING").boosts[1] == 2);

        std::cout << "Passed abilities/boosts tests" << std::endl;
    }

    SECTION("Size") {
        INFO("Size Tests");
        std::cout << "Starting race/size Tests..." << std::endl;

        CHECK(eztp::Race::getRace("HALF-ORC").size == 'M');
        CHECK(eztp::Race::getRace("LIGHTFOOT HALFLING").size == 'S');
        CHECK(eztp::Race::getRace("HUMAN").size == 'M');

        std::cout << "Passed size tests" << std::endl;
    }

    SECTION("Speed") {
        INFO("Speed Tests");
        std::cout << "Starting race/speed Tests..." << std::endl;

        CHECK(eztp::Race::getRace("HALF-ELF").speed == 30);
        CHECK(eztp::Race::getRace("HILL DWARF").speed == 25);
        CHECK(eztp::Race::getRace("HUMAN").speed == 30);

        std::cout << "Passed speed tests" << std::endl;
    }

    SECTION("Saving") {
        INFO("Save Tests");
        std::cout << "Starting race/save Tests" << std::endl;

        CHECK(eztp::Race::save());
        CHECK(eztp::Race::save("testRace.json"));

        std::cout << "Passed save tests" << std::endl;
    }

    SECTION("Loading") {
        INFO("Load Tests");
        std::cout << "Starting race/load Tests" << std::endl;

        CHECK(eztp::Race::load());
        CHECK(eztp::Race::load("testRace.json"));

        std::cout << "Passed load tests" << std::endl;
    }
}

TEST_CASE("Background data is accessible", "[background]") {
    SECTION("gp") {
        INFO("gp Tests");
        std::cout << "Starting background/gp Tests..." << std::endl;

        CHECK(eztp::Background::getBg("ACOLYTE").gp == 15);

        std::cout << "Passed gp tests" << std::endl;
    }

    SECTION("Proficiencies") {
        INFO("Proficiencies Tests");
        std::cout << "Starting background/proficiencies Tests..." << std::endl;

        CHECK(eztp::Background::getBg("ACOLYTE").prof[1] == "RELIGION");

        std::cout << "Passed proficiencies tests" << std::endl;
    }

    SECTION("Equipment") {
        INFO("Equipment Tests");
        std::cout << "Starting background/equipment Tests..." << std::endl;

        CHECK(eztp::Background::getBg("ACOLYTE").equip[0] == "Holy Symbol");

        std::cout << "Passed equipment tests" << std::endl;
    }

    SECTION("Saving") {
        INFO("Save Tests");
        std::cout << "Starting background/save Tests" << std::endl;

        CHECK(eztp::Background::save());
        CHECK(eztp::Background::save("testBackground.json"));

        std::cout << "Passed save tests" << std::endl;
    }

    SECTION("Loading") {
        INFO("Load Tests");
        std::cout << "Starting background/load Tests" << std::endl;

        CHECK(eztp::Background::load());
        CHECK(eztp::Background::load("testBackground.json"));

        std::cout << "Passed load tests" << std::endl;
    }
}