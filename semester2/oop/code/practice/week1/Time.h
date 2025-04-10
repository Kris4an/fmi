#ifndef TIME_H
#define TIME_H
#include <iostream>

struct Time
{
    int hours;
    int minutes;
    int seconds;

    void addSeconds(int s);
    void addMinutes(int m);
    void addHours(int h);
    void print() const;
};

void Time::print() const {
    std::cout<<hours<<":"<<minutes<<":"<<seconds;
}

void Time::addSeconds(int s) {
    seconds += s;

    minutes += seconds/60;

    seconds = seconds%60;

    hours += minutes/60;

    minutes = minutes%60;
}

void Time::addMinutes(int m) {
    minutes += m;

    hours += minutes/60;

    minutes = minutes%60;
}

void Time::addHours(int h) {
    hours += h;
}


#endif