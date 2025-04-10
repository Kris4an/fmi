#pragma once
#include <iostream>
#include <cstring>

class Book{
    char* title;
    char* author;
    char* genre;
    short pages;
    short yearOfPublishing;

    void freeMemory();
    void copy(const char* title, const char* author, const char* genre);
public:
    Book();
    Book(const char* title, const char* author, const char* genre, int pages, int yearOfPublishing);
    Book(const Book& other);

    ~Book();

    Book& operator=(const Book& other);
    bool operator==(const Book& other) const;
    bool operator<(const Book& other) const;
    friend std::ostream& operator<<(std::ostream&, const Book& book);

    std::ostream& binPrint(std::ostream&);
    void print();
};