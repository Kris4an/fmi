#include <cstring>
#include "catch2/catch_all.hpp"
#include "ucn.h"

const char correctUCN[11] = "0847038794";
TEST_CASE("ucn constructor and to_string function")
{
    SECTION("Correct argument")
    {
        ucn egn(correctUCN);

        REQUIRE(std::strcmp(correctUCN, egn.to_string()) == 0);
    }
    SECTION("Incorrect artgument")
    {
        REQUIRE_THROWS_AS(ucn("123456789"), std::invalid_argument);
    }
}

TEST_CASE("ucn year function")
{
    ucn egn(correctUCN);
    REQUIRE(egn.year() == 2008);
}

TEST_CASE("ucn month function")
{
    ucn egn(correctUCN);
    REQUIRE(egn.month() == 7);
}

TEST_CASE("ucn day function")
{
    ucn egn(correctUCN);
    REQUIRE(egn.day() == 3);
}

TEST_CASE("ucn region function")
{
    ucn egn(correctUCN);
    REQUIRE(egn.region() == std::string("Shumen"));
}

TEST_CASE("ucn is_valid_ucn function")
{
    SECTION("Correct arguments")
    {
        REQUIRE(ucn::is_valid_ucn("0042290000"));
        REQUIRE(ucn::is_valid_ucn("0404271406"));
    }
    SECTION("Wrong format")
    {
        REQUIRE_FALSE(ucn::is_valid_ucn("abcdefghij"));
        REQUIRE_FALSE(ucn::is_valid_ucn("123456"));
        REQUIRE_FALSE(ucn::is_valid_ucn("04042714069"));
        char egn[] = "040427140";
        egn[9] = 6;
        REQUIRE_FALSE(ucn::is_valid_ucn(egn));
    }
    SECTION("Wrong date")
    {
        REQUIRE_FALSE(ucn::is_valid_ucn("0076123456"));
        REQUIRE_FALSE(ucn::is_valid_ucn("2155123456"));
        REQUIRE_FALSE(ucn::is_valid_ucn("0002291234"));
        REQUIRE_FALSE(ucn::is_valid_ucn("0244311234"));
    }
    SECTION("Wrong check number")
    {
        REQUIRE_FALSE(ucn::is_valid_ucn("1012191436"));
    }
}