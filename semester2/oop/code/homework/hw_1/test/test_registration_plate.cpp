#define CORRECT_ARGUMENTS_COUNT 7
#define WRONG_ARGUMENTS_COUNT 6
#include "catch2/catch_all.hpp"
#include "registration_plate.h"
#include <cstring>
#include <sstream>


//const char correctArguments[CORRECT_ARGUMENTS_COUNT][9] = {"AA1234BB", "A0001ZZ", "BC9876NH", "AA1234CB", "A1000ZZ", "BA5676PP", "AA1087HH"};

const char* correctArguments(int index)
{
    switch (index)
    {
    case 0:
        return "AA1234BG";
    case 1:
        return "A0001ZZ";
    case 2:
        return "BC9876NH";
    case 3:
        return "AA1234CB";
    case 4:
        return "A1000ZZ";
    case 5:
        return "BA5676PP";
    case 6:
        return "AA1087HH";
    default:
        throw std::invalid_argument("Wrong index when getting a correct argument");
    }
}

const char* wrongArguments(int index)
{
    switch (index)
    {
    case 0:
        return "AA1234B";
    case 1: 
        return "A0001Z";
    case 2: 
        return "BCB876NH";
    case 3: 
        return "1234ABCD";
    case 4: 
        return "BGJK1234";
    case 5: 
        return "1234";    
    default:
        throw std::invalid_argument("Wrong index when getting a correct argument");
    }
}

TEST_CASE("Constructor and to_string function")
{

    SECTION("Correct arguments")
    {

        for(int i = 0; i < CORRECT_ARGUMENTS_COUNT; ++i){
            registration_plate rp(correctArguments(i));

            REQUIRE(std::strcmp(rp.to_string(), correctArguments(i)) == 0);
        }

    }

    SECTION("Wrong arguments")
    {
        for(int i = 0; i < WRONG_ARGUMENTS_COUNT; ++i){
            REQUIRE_THROWS_AS(registration_plate(wrongArguments(i)), std::invalid_argument);
        }
    }
}

TEST_CASE("registration_plate operator< and operator==")
{
    for(int i = 0; i < CORRECT_ARGUMENTS_COUNT; ++i)
    {
        for(int j = 0; j < CORRECT_ARGUMENTS_COUNT; ++j)
        {
            registration_plate rp1(correctArguments(i));
            registration_plate rp2(correctArguments(j));
            int check = std::strcmp(correctArguments(i), correctArguments(j));

            CAPTURE(i, j, check);
            CAPTURE(correctArguments(i), correctArguments(j));

            REQUIRE((rp1 < rp2) == (check < 0));
            REQUIRE((rp1 == rp2) == (check == 0));
        }
    }
}

