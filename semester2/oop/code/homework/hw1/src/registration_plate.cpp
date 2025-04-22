#include "registration_plate.h"
#include <cstring>
#include <stdexcept>

registration_plate::registration_plate(const char* plate)
{
    int plateLen = std::strlen(plate);
    if(plateLen < 7 || plateLen > 8) 
        throw std::invalid_argument("Plate number cannot be less than 7 or more 8 symbols");

    bool shortPrefix = (plateLen == 7);

    if(plate[0] < 'A' || plate[0] > 'Z')
        throw std::invalid_argument("Prefix must contain only capital latin letters");

    if(shortPrefix)
    {
        for(int i = 1; i <= 4; ++i)
        {
            if(plate[i] < '0' || plate[i] > '9')
                throw std::invalid_argument("Number must contain only the numbers from 0 to 9");
        }
        for(int i = 5; i <= 6; ++i)
        {
            if(plate[0] < 'A' || plate[0] > 'Z')
                throw std::invalid_argument("Sufix must contain only capital latin letters");
        }
    }
    else
    {
        if(plate[1] < 'A' || plate[1] > 'Z')
            throw std::invalid_argument("Prefix must contain only capital latin letters");

        for(int i = 2; i <= 5; ++i)
        {
            if(plate[i] < '0' || plate[i] > '9')
                throw std::invalid_argument("Number must contain only the numbers from 0 to 9");
        }
        for(int i = 6; i <= 7; ++i)
        {
            if(plate[0] < 'A' || plate[0] > 'Z')
                throw std::invalid_argument("Sufix must contain only capital latin letters");
        }
    }

    std::copy(plate, plate + plateLen, this->plate);
}