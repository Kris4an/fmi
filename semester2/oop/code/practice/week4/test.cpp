#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "bankAccount.hpp"


TEST_CASE("Deposit")
{
    BankAccount ba(0);
    SECTION("Deposit correct value")
    {
        ba.deposit(100);
        REQUIRE(ba.getBalance() == 100);
    }
    SECTION("Deposit incorrect value")
    {
        REQUIRE_THROWS_AS(ba.deposit(-100), std::invalid_argument);
    }
}

TEST_CASE("Withdraw")
{
    BankAccount ba(500);
    SECTION("Withdraw correct value")
    {
        ba.withdraw(100);
        REQUIRE(ba.getBalance() == 400);
    }
    SECTION("Withdraw incorrect value")
    {
       REQUIRE_THROWS_AS(ba.withdraw(1000), std::invalid_argument);
    }
}

TEST_CASE("Transfer")
{
    BankAccount ba1(300);
    BankAccount ba2(300);

    SECTION("Transfer correct value")
    {
        ba1.transfer(ba2, 200);
        REQUIRE(ba1.getBalance() == 100);
        REQUIRE(ba2.getBalance() == 500);
    }
    SECTION("Transfer incorrect value")
    {
        REQUIRE_THROWS_AS(ba1.transfer(ba2, 400), std::invalid_argument);
        REQUIRE(ba1.getBalance() == 300);
        REQUIRE(ba2.getBalance() == 300);
    }
}