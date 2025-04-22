#pragma once
#include <iostream>

class registration_plate{
    char plate[8];

public:
    registration_plate(const char*);
    bool operator<(const registration_plate&) const noexcept;
    bool operator==(const registration_plate&) const noexcept;
    const char* to_string() const noexcept;
    //friend istream& operator>>(istream&, registration_plate&);
    //friend ostream& operator<<(ostream&, const registration_plate&);
};