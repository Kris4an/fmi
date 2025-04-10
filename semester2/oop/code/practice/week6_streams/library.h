#pragma once
#include <iostream>
#include "book.h"


class Library{
    Book* books;
    size_t size;
    size_t capacity;

    void freeMemory();
    void copy(const Library& other);
    void enlarge();
    void shrink();
    void saveToTxtFile(const char* filename) const;
    void saveToBinFile(const char* filename) const;
public:
    Library();
    Library(const Library& other);
    void addBook(const Book& b);
    void removeBook(const Book& b);
    Book& findBookByTitle(const char* title) const;
    void listBooks() const;
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
    Library& operator[](int index) const;
    Library& operator=(const Library& other);
    Library& operator+ (const Library& other);
    bool operator== (const Library& other);
    friend std::ostream& operator<<(std::ostream& out, const Library& lib);
};