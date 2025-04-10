#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <stdexcept>

class BankAccount {
    private:
        unsigned int id;
        unsigned int balance;
    public:
        BankAccount() {
            this->id = 0;
            this->balance = 0;
        }
        BankAccount(unsigned int balance){
            id = 0;
            this->balance = balance;
        }

        // BankAccount(unsigned int id, unsigned int balance){
        //     (*this).id = id; //защото this е pointer към инстанцията на нашия обект
        //     this->balance = balance;
        // }

        BankAccount(unsigned id, unsigned balance) : id(id), balance(balance) {};

        unsigned int getBalance() const{
            return balance;
        }

        void withdraw(unsigned int  sum){
            if(sum > balance){
                throw std::invalid_argument("Not enough money!");
                return;
            }
            balance -= sum;
        }
};

#endif