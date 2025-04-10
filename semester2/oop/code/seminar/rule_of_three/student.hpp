#pragma once
#include <string.h>

class Student
{
    char* name;

public:
    Student();
    Student(const char*);
    Student(Student& other);
    ~ Student();
    Student& operator=(const Student& other);
};

Student::Student()
{
    name = nullptr;
}

Student::Student(const char* name)
{
    this->name = new char[strlen(name) - 1];
    strcpy(this->name, name);
}

Student::Student(Student& other)
{
    this->name = new char[strlen(other.name) - 1];
    strcpy(this->name, other.name);
}

Student::~Student()
{
    delete [] this->name;
}

Student& Student::operator=(const Student& other)
{
    if(this == &other) return;

    const int otherNameSize = strlen(other.name);
    if(strlen(this->name) != otherNameSize)
    {
        delete [] name;
        name = new char[otherNameSize];
    }

    strcpy(this->name, other.name);
}