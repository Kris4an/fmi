#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

struct Employee
{
    const char* name;
    char* position;
    int salary;
    int workExperience;

    double getBonus() const;
    void print() const;
};

double Employee::getBonus() const{
    return salary*(workExperience+1)/100.0;
}
void Employee::print() const{
    std::cout <<"name: "<< name << ", position: " << position << ", salary: " << salary << "lv, work experience: " << workExperience << " years, bonus: " << getBonus() << "lv";
}

#endif