#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>

class Vector
{
    int* arr;
    unsigned int size;
    unsigned int capacity;

    void freeMemory();
    void copyObj(Vector& other);
    void enlarge();
    void shrink();

    Vector(int size, int capacity, int* arr);
public:
    Vector();
    Vector(Vector& other);
    ~Vector();

    Vector& operator=(Vector& other);
    int operator[](int index);
    bool operator==(Vector& other);
    friend std::ostream& operator<<(std::ostream& os, const Vector&);
    int operator*(Vector& other);

    void push_back(int value);
    void pop_back();
    int at(int index) const;
    void insertAt(int index, int value);
    void deleteAt(int index);
    void sort();
    void concat(Vector& other);
    Vector slice(int start, int end);
    void reverse();
    int getSize() const;
    int getCapacity() const;
};

#endif