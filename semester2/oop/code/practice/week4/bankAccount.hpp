#pragma once

class BankAccount
{
    static int idCnt;
    long id;
    long balance;

public:
    BankAccount();
    BankAccount(long amount);
    void deposit(long amount);
    void withdraw(long amount);
    void transfer(BankAccount& other, long amount);
    long getBalance() const;
};
