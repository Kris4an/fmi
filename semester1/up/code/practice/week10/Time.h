#include <iostream>
#ifndef TIME_H
#define TIME_H

struct Time
{
    int hours, minutes, seconds;

    Time(int h, int m, int s) {
        if(h<0 || h>=24 || m<0 || m>=60 || s<0 || s>=60){
            throw std::invalid_argument("Bad arguments");
        }
        hours = h;
        minutes = m;
        seconds = s;
    }

    int difference(Time t){
        return abs(hours*3600+minutes*60+seconds - t.hours*3600-t.minutes*60-t.seconds);
    }
};


#endif