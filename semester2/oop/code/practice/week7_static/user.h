#pragma once
#include <iostream>
#include "role.h"

class User{
    static size_t userCount;
    static char** emailsInUse;

    size_t id;
    char* name;
    unsigned short age;
    char* email;
    Role role;

    void copy(const User&);
    void freeMemory();
public:
    User();
    User(char*, unsigned short, char*, Role);
    User(const User&);

    ~User();
    User& operator=(const User&);

    void print() const;
    bool operator==(const User&);
    friend std::ostream& operator<<(std::ostream&, const User&);
    int getUserCount();
};