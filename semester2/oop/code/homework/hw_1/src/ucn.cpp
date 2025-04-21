#include <stdexcept>
#include <string>
#include <cstring>
#include <iostream>
#include "ucn.h"

ucn::ucn(const char* str)
{
    if(is_valid_ucn(str)){
        std::copy(str, str + 10, number);
    }
    else{
        throw std::invalid_argument("Ivalid ucn");
    }
}



int ucn::year() const
{
    return getYear(number);
}

int getYear(const char* number)
{
    short baseYear = 1900;
    if(number[2] == '2' || number[2] == '3') baseYear = 1800;
    if(number[2] == '4' || number[2] == '5') baseYear = 2000;

    return 1900 + (number[0] - '0')*10 + (number[1] - '0');
}

int ucn::month() const
{
    return getMonth(number);
}

int getMonth(const char* number)
{
    return ((number[2] - '0') % 2 ) * 10 + (number[3] - '0');
}

int ucn::day() const
{
    return getDay(number);
}
int getDay(const char* number)
{
    return (number[4] - '0') * 10 + (number[5] - '0');
}

const char* ucn::to_string() const
{
    return number;
}

std::istream& operator>>(std::istream& inStream, ucn& egn)
{
    char num[11];
    inStream >> num;
    
    egn = ucn(num);

    return inStream;
}

std::ostream& operator<<(std::ostream& outStream, const ucn& egn)
{
    outStream << egn.to_string();

    return outStream;
}

bool isNumber(const char& c)
{
    return ('0' < c && c < '9');
}

bool ucn::is_valid_ucn(const char* str)
{
    if(std::strlen(str) != 10) throw std::invalid_argument("UCN must be exactly 10 characters long");
    
    for(int i = 0; i < 10; ++i)
    {
        if(!isNumber(str[i])) throw std::invalid_argument("UCN must contain only numbers");
    }

    if(str[3] < '0' || str[3] > '5') 
        throw std::invalid_argument("Invalid month");

    if((str[3] == '0' || str[3] == '4' || str[3] == '2') && str[4] > '2')
        throw std::invalid_argument("Invalid month");
    
    
}

std::string ucn::region()
{
    int number = (this->number[6] - '0') * 100 + (this->number[7] - '0') * 10 + (this->number[8] - '0');

    if (number >= 0 && number <= 43)
        return "Blagoevgrad";
    else if (number >= 44 && number <= 93)
        return "Burgas";
    else if (number >= 94 && number <= 139)
        return "Varna";
    else if (number >= 140 && number <= 169)
        return "Veliko Tarnovo";
    else if (number >= 170 && number <= 183)
        return "Vidin";
    else if (number >= 184 && number <= 217)
        return "Vratsa";
    else if (number >= 218 && number <= 233)
        return "Gabrovo";
    else if (number >= 234 && number <= 281)
        return "Kardzhali";
    else if (number >= 282 && number <= 301)
        return "Kyustendil";
    else if (number >= 302 && number <= 319)
        return "Lovech";
    else if (number >= 320 && number <= 341)
        return "Montana";
    else if (number >= 342 && number <= 377)
        return "Pazardzhik";
    else if (number >= 378 && number <= 395)
        return "Pernik";
    else if (number >= 396 && number <= 435)
        return "Pleven";
    else if (number >= 436 && number <= 501)
        return "Plovdiv";
    else if (number >= 502 && number <= 527)
        return "Razgrad";
    else if (number >= 528 && number <= 555)
        return "Ruse";
    else if (number >= 556 && number <= 575)
        return "Silistra";
    else if (number >= 576 && number <= 601)
        return "Sliven";
    else if (number >= 602 && number <= 623)
        return "Smolyan";
    else if (number >= 624 && number <= 721)
        return "Sofia (City)";
    else if (number >= 722 && number <= 751)
        return "Sofia (District)";
    else if (number >= 752 && number <= 789)
        return "Stara Zagora";
    else if (number >= 790 && number <= 821)
        return "Dobrich";
    else if (number >= 822 && number <= 843)
        return "Targovishte";
    else if (number >= 844 && number <= 871)
        return "Haskovo";
    else if (number >= 872 && number <= 903)
        return "Shumen";
    else if (number >= 904 && number <= 925)
        return "Yambol";
    else if (number >= 926 && number <= 999)
        return "Other/Unknown";
    else
        return "Invalid number";
}
