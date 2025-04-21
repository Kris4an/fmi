#pragma once
#include <iostream>

class registration_plate{
    char plate[9];

public:
    registration_plate(const char*);
    friend bool operator<(const registration_plate&, const registration_plate&);
    friend bool operator==(const registration_plate&, const registration_plate&);
    const char* to_string() const;
    friend std::istream& operator>>(std::istream&, registration_plate&);
    friend std::ostream& operator<<(std::ostream&, const registration_plate&);
};