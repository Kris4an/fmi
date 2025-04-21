#pragma once
#include <string>
#include <iostream>

class ucn{
    char number[11];
private:
    ucn(const char*);
    int year() const;
    int month() const;
    int day() const;
    std::string region();
    static bool is_valid_ucn(const char*);
    const char* to_string() const;
    friend std::istream& operator>>(std::istream&, ucn&);
    friend std::ostream& operator<<(std::ostream&, const ucn&);
};