#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <fstream>
#include <iostream>
#include "algorithms/SHA256.h"
#include <string>

enum Algorithms
{
    sha256,
    md5
};

class Calculator
{
public:
    Calculator() {};

    std::string calculateChecksum(std::ifstream &file, Algorithms algorithm)
    {
        std::string fileContents = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        switch (algorithm)
        {
            case Algorithms::sha256:
            {
                SHA256 sha;
                sha.update(fileContents);
                std::array<uint8_t, 32> digest = sha.digest();

                return SHA256::toString(digest);
            }
            break;
        }
        
        return "";
    }
};

#endif
