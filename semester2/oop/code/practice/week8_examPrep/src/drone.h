#pragma once

class Drone{

    struct Point
    {
        double x, y;
        Point(): x(0), y(0) {}
        Point(double x, double y) : x(x), y(y) {}
    };
    

    char* id;
    Point coords[63];
    unsigned pathSize;
    int curentPosition;

public:
    Drone(const char* fileName, const char* id);
    Drone(const Drone& other);
    ~Drone();
    Drone& operator=(const Drone& other);
    
    void printGeneratedPath() const;
    void moveOneStep();
};