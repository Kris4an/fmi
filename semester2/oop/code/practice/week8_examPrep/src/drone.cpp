#include "drone.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdexcept>

Drone::Drone(const char* fileName, const char* id)
{
    this->curentPosition = 0;
    this->pathSize = 0;

    this->id = new char[strlen(id) + 1];
    std::strncpy(this->id, id, strlen(id) + 1);

    std::ifstream input(fileName, std::ios::binary);

    if(!input.is_open()){
        throw std::invalid_argument("Invalid name");
    }

    while(!input.eof())
    {
        double x, y;

        input.read((char*)&x, sizeof(x));
        input.read((char*)&y, sizeof(y));

        

        coords[pathSize] = Point(x,y);
        pathSize++;

    }

    input.close();

}

//todo rule of 3

Drone::~Drone() {
    delete [] id;
}

void Drone::printGeneratedPath() const {
    for(int i = 0; i < pathSize; i++){
        std::cout << "(" << coords[i].x << " " << coords[i].y << ")\n";
    }
}

void Drone::moveOneStep() {
    curentPosition++;
}