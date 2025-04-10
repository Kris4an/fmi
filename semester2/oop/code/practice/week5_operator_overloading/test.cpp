#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector.hpp"
#include <stdexcept>


TEST_CASE("Push_back")
{
    Vector v;
    SECTION("Push back a single element")
    {
        v.push_back(1);
        REQUIRE(v.at(0) == 1);
    }
    SECTION("Push back with enlargment")
    {
        for(int i = 1; i <= 9; ++i) v.push_back(i);
        REQUIRE(v.at(8) == 9);
        REQUIRE(v.getCapacity() == 16);
    }
}
TEST_CASE("Pop_back")
{
    Vector v;
    SECTION("Incorrect pop back")
    {
        REQUIRE_THROWS_AS(v.pop_back(), std::out_of_range);
    }
    SECTION("Correct pop back")
    {
        v.push_back(1);
        v.pop_back();
        REQUIRE_THROWS_AS(v.at(0), std::invalid_argument);
    }
}

TEST_CASE("At")
{
    Vector v;
    v.push_back(1);

    SECTION("Get at a correct position")
    {
        REQUIRE(v.at(0) == 1);
    }

    SECTION("Get at an incorrect position")
    {
        REQUIRE_THROWS_AS(v.at(1), std::invalid_argument);
    }
}

TEST_CASE("Delete at")
{
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    SECTION("Delete at a correct middle position")
    {
        v.deleteAt(1);
        REQUIRE(v.at(1) == 3);
        REQUIRE_THROWS_AS(v.at(2), std::invalid_argument);
    }
}

TEST_CASE("InsertAt")
{
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    SECTION("Insert at correct middle position")
    {
        v.insertAt(1,4);
        REQUIRE(v.at(1) == 4);
        REQUIRE(v.at(3) == 3);
        REQUIRE(v.at(0) == 1);
    }

    SECTION("Insert at correct end position")
    {
        v.insertAt(3,4);
        REQUIRE(v.at(2) == 3);
        REQUIRE(v.at(3) == 4);
    }

    SECTION("Insert at first position")
    {
        v.insertAt(0, 4);
        REQUIRE(v.at(0) == 4);
        REQUIRE(v.at(1) == 1);
    }

    SECTION("Insert at last position and enlarge array")
    {
        for(int i = 4; i <= 8; ++i) v.push_back(i);

        REQUIRE_NOTHROW(v.insertAt(8, 9));
        REQUIRE(v.at(8) == 9);
    }

    SECTION("Insert at incorrect position")
    {
        REQUIRE_THROWS_AS(v.insertAt(4, 4), std::invalid_argument);
    }
}