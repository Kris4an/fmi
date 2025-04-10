#include "bankAccount.hpp"
#include "stdexcept"

int BankAccount::idCnt = 0;

BankAccount::BankAccount()
{
    this->id = idCnt;
    ++idCnt;
    this->balance = 0;
}

BankAccount::BankAccount(long amount)
{
    this->id = idCnt;
    ++idCnt;

    if(amount < 0) throw std::invalid_argument("Amount could not be nagetive");

    (*this).balance = amount;
}

void BankAccount::deposit(long amount)
{
    if(amount < 0) throw std::invalid_argument("Amount could npt be nagetive");

    this->balance += amount;
}

void BankAccount::withdraw(long amount)
{
    if(amount > this->balance) throw std::invalid_argument("Could not withdraw more money than already in balance");

    this->balance -= amount;
}

void BankAccount::transfer(BankAccount& other, long amount)
{
    if(amount > this->balance) throw std::invalid_argument("Could not transfer more money than already in balance");

    this->balance -= amount;
    other.balance += amount;
}

long BankAccount::getBalance() const
{
    return this->balance;
}