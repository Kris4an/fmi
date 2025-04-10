#include "user.h"

void User::copy(const User& other)
{

}

void User::freeMemory()
{
    delete [] email;
    delete [] name;
}

User::User()
{
    id = userCount;
    ++userCount;
    name = nullptr;
    age = 0;
    email = nullptr;
    role = Role::USER;
}

User::User(char* name, unsigned short age, char* email, Role role)
{

}