#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

class Student
{
    char *firstName;
    char *lastName;
    unsigned int specialtyId;

    void copy(const Student &other);
    void freeMemory();

public:
    Student();

    Student(const char *firstName, const char *lastName, unsigned int specialtyId);

    Student(const Student &other);

    Student& operator=(const Student& other);

    ~Student();

    void print() const;

    bool hasSameSpecialty(const Student& other) const;

    void changeSpecialty(unsigned specialtyId);
};

void Student::copy(const Student &other)
{
    if (other.firstName)
    {
        this->firstName = new char[std::strlen(other.firstName) + 1];
        std::strcpy(this->firstName, other.firstName);
    }
    else
        this->firstName = nullptr;

    if (other.lastName)
    {
        this->lastName = new char[std::strlen(other.lastName) + 1];
        std::strcpy(this->lastName, other.lastName);
    }
    else
        this->lastName = nullptr;

    this->specialtyId = other.specialtyId;
}

void Student::freeMemory()
{
    delete[] this->firstName;
    delete[] this->lastName;
    this->firstName = nullptr;
    this->lastName = nullptr;
}

Student::Student()
{
    firstName = nullptr;
    lastName = nullptr;
    specialtyId = 0;
}

Student::Student(const char *firstName, const char *lastName, unsigned int specialtyId) : specialtyId(specialtyId)
{
    if (firstName)
    {
        this->firstName = new char[std::strlen(firstName) + 1];
        std::strcpy(this->firstName, firstName);
    }
    else
        this->firstName = nullptr;

    if (lastName)
    {
        this->lastName = new char[std::strlen(lastName) + 1];
        std::strcpy(this->lastName, lastName);
    }
    else
        this->lastName = nullptr;
}

Student::Student(const Student& other)
{
    copy(other);
}

Student& Student::operator=(const Student& other)
{
    if(this != &other){
        freeMemory();
        copy(other);
    }
    return *this;
}

Student::~Student()
{
    freeMemory();
}

void Student::print() const
{
    std::cout << "Name: " << this->firstName << " " << this->lastName << ", Specalty ID: " << this->specialtyId;
}

bool Student::hasSameSpecialty(const Student& other) const
{
    return this->specialtyId == other.specialtyId;
}

void Student::changeSpecialty(unsigned int specialtyID)
{
    this->specialtyId = specialtyID;
}

#endif