#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>

struct Student {

    std::string name;
    int age;
    double avgGrade;

    void printDetails() const;
};

#endif