#include "library.h"
#include <fstream>
#include <iostream>

void Library::freeMemory()
{
    delete[] books;
}

void Library::copy(const Library &other)
{
    capacity = other.capacity;
    size = other.size;
    books = new Book[capacity];

    std::copy(other.books, other.books + other.size, books);
}

void Library::enlarge()
{
    capacity*=2;
    Book* newBooks = new Book[capacity];

    std::copy(books, books + size, newBooks);

    freeMemory();

    books = newBooks;
}

void Library::shrink()
{
    if(capacity == 8) return;

    capacity/=2;
    Book* newBooks = new Book[capacity];

    std::copy(books, books + size, newBooks);

    freeMemory();

    books = newBooks;
}

void Library::saveToTxtFile(const char* filename) const
{
    std::ofstream outFile(filename, std::ios::out);

    if(!outFile) 
    {
        std::cerr << "Could not open file" << std::endl;
        return;
    }

    outFile << *this;

    outFile.close();
}

void Library::saveToBinFile(const char* filename) const
{
    std::ofstream outFile(filename, std::ios::out | std::ios::binary);
    
    return;
}

Library::Library()
{
    size = 0;
    capacity = 8;
    books = new Book[capacity];
}

Library::Library(const Library &other)
{
    copy(other);
}

Library &Library::operator=(const Library &other)
{
    freeMemory();
    copy(other);

    return *this;
}

void Library::addBook(const Book& b) //add sort?
{
    if(size == capacity) enlarge();
    books[size] = b;

    ++size;
}

void Library::removeBook(const Book &b)
{
    for(int i = 0; i < size; ++i){
        if(books[i] == b)
        {
            for(int j = i; j < size - 1; ++j){
                books[j] = books[j+1];
            }
            break;
        }
    }

    --size;
    if(size <= capacity/4 && capacity > 8) shrink();
}
// Book &findBookByTitle(const char *title) const;
void Library::listBooks() const
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << books[i] << '\n';
    }
}
void Library::saveToFile(const char *filename) const
{
    char* dot = std::strrchr(filename, '.');

    if(dot == nullptr) throw std::invalid_argument("File must have an extension");

    if(strcmp(dot, ".txt") == 0) saveToTxtFile(filename);
    else {
        if(strcmp(dot, ".bin") == 0) saveToBinFile(filename);
        else throw std::invalid_argument("Invalid file extension");
    }
}
// void loadFromFile(const char *filename);
// Library &operator[](int index);
std::ostream& operator<<(std::ostream& out, const Library& lib)
{
    out << lib.capacity << '\n' 
        << lib.size     << '\n';
    for(int i = 0; i < lib.size; ++i)
    {
        out << lib.books[i] << '\n';
    }

    return out;
}