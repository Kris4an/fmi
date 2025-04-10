#include <iostream>
#include "BankAccount.h"
#include "Rational.h"

int main(){
    //BankAccount acc(1, 29);
    Rational q(-16,5);
    Rational r(1,4);

    q.add(r).print();
    std::cout << std::endl;

    q.subtract(r).print();
    std::cout << std::endl;

    q.multiply(r).print();
    std::cout << std::endl;

    q.divide(r).print();
    std::cout << std::endl;

    std::cout << q.isInteger() << std::endl;

    std::cout << q.floor() << std::endl;

    std::cout << q.ceil();
}