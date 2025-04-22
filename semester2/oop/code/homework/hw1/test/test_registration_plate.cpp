#define CORRECT_ARGUMENTS_COUNT 7
#include "catch2/catch_all.hpp"
#include "registration_plate.h"
#include <cstring>


const char correctArguments[CORRECT_ARGUMENTS_COUNT][9] = {"AA1234BB", "A0001ZZ", "BC9876NH", "AA1234CB", "A1000ZZ", "BA5676PP", "AA1087HH"};

TEST_CASE("Constructor and to_string function")
{

    SECTION("Correct arguments")
    {

        for(int i = 0; i < CORRECT_ARGUMENTS_COUNT; ++i){
            registration_plate rp(correctArguments[i]);

            REQUIRE(std::strcmp(rp.to_string(), correctArguments[i]) == 0);
        }

    }

    SECTION("Wrong arguments")
    {
        char arguments[][9] = {"AA1234B", "A0001Z", "BCB876NH", "1234ABCD", "BGJK1234", "1234"};

        for(int i = 0; i < 6; ++i){
            REQUIRE_THROWS_AS(registration_plate(arguments[i]), std::invalid_argument);
        }
    }
}

TEST_CASE("registration_plate operator< and operator==")
{
    for(int i = 0; i < CORRECT_ARGUMENTS_COUNT; ++i)
    {
        for(int j = 0; j < CORRECT_ARGUMENTS_COUNT; ++j)
        {
            registration_plate rp1(correctArguments[i]);
            registration_plate rp2(correctArguments[j]);
            int check = std::strcmp(correctArguments[i], correctArguments[j]);

            REQUIRE(rp1 < rp2 && check < 0);
            REQUIRE(rp1 == rp2 && check == 0);
        }
    }
}
