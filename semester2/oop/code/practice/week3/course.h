#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <cstring>
#include "student.h"

class Course
{
    char *courseName;
    char *courseCode;
    Student *students;
    size_t studentCount;
    size_t copacity;

    void copy(const Course &other);
    void freeMemory();

public:
    Course();
    Course(const char *courseName, const char *courseCode, Student *students, size_t studentCount, size_t copacity);
    Course(const Course &other);
    Course &operator=(const Course &other);
    ~Course();
};

void Course::copy(const Course &other)
{
    if (courseName)
    {
        this->courseName = new char[std::strlen(courseName) + 1];
        std::strcpy(this->courseName, courseName);
    }
    else
        this->courseName = nullptr;

    if (courseCode)
    {
        this->courseCode = new char[std::strlen(courseCode) + 1];
        std::strcpy(this->courseCode, courseCode);
    }
    else
        this->courseCode = nullptr;

    students = new Student[other.studentCount];

    this->studentCount = other.studentCount;
    this->copacity = other.copacity;

    for(int i = 0; i < this->studentCount; ++i)
    {
        students[i] = other.students[i];
    }
}

void Course::freeMemory()
{
    delete[] this->courseName;
    delete[] this->courseCode;
    delete[] this->students;

    this->courseName = nullptr;
    this->courseCode = nullptr;
    this->students = nullptr;
}

Course::Course()
{
    courseCode = nullptr;
    courseCode = nullptr;
    students = nullptr;
    studentCount = 0;
    copacity = 0;
}

Course::Course(const char *courseName, const char *courseCode, Student *students, size_t studentCount, size_t copacity) : students(students), studentCount(studentCount), copacity(copacity)
{
    if (courseName)
    {
        this->courseName = new char[std::strlen(courseName) + 1];
        std::strcpy(this->courseName, courseName);
    }
    else
        this->courseName = nullptr;

    if (courseCode)
    {
        this->courseCode = new char[std::strlen(courseCode) + 1];
        std::strcpy(this->courseCode, courseCode);
    }
    else
        this->courseCode = nullptr;
}

Course::Course(const Course& other)
{
    copy(other);
}

Course::~Course()
{
    freeMemory();
}

#endif