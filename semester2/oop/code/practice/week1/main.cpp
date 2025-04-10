/*
Принципи в ООП
1. Абстракция
2. Енкапсулация (data hiding)
-сигурност
3. Наследяване
Animal <- Cat
       <- Dog
4. Полиморфизъм

*/

#include <iostream>
#include "ComplexNumber.h"
#include "Time.h"
#include "Employee.h"

int main(){
    // ComplexNumber c1 {0, 1};
    // ComplexNumber c2 {0, 1};
    // c2.multiply(c1).print();

    // Time t1 {0, 59, 0};
    // t1.addMinutes(170);
    // t1.print();

    char* name = new char[5] {"Ivan"};

    char pos[] = "driver";
    const char* n = "Ivan";
    Employee e {n, pos, 2300, 4};
    e.print();
    return 0;
}