#include <cstring>
#include "book.h"

void Book::freeMemory()
{
    delete[] title;
    delete[] author;
    delete[] genre;
}

void Book::copy(const char *title, const char *author, const char *genre)
{
    int titleSize = strlen(title) + 1;
    this->title = new char[titleSize];
    std::copy(title, title + titleSize, this->title);

    int authorSize = strlen(author) + 1;
    this->author = new char[authorSize];
    std::copy(author, author + authorSize, this->author);

    int genreSize = strlen(genre) + 1;
    this->genre = new char[genreSize];
    std::copy(genre, genre + genreSize, this->genre);
}

Book::Book()
{
    title = author = genre = nullptr;
    pages = yearOfPublishing = 0;
}
Book::Book(const char *title, const char *author, const char *genre, int pages, int yearOfPublishing)
{
    copy(title, author, genre);

    this->pages = pages;
    this->yearOfPublishing = yearOfPublishing;
}
Book::Book(const Book &other)
{
    copy(other.title, other.author, other.genre);

    this->pages = other.pages;
    this->yearOfPublishing = other.yearOfPublishing;
}

Book::~Book()
{
    freeMemory();
}

Book& Book::operator=(const Book &other)
{
    freeMemory();
    copy(other.title, other.author, other.genre);

    pages = other.pages;
    yearOfPublishing = other.yearOfPublishing;

    return *this;
}
bool Book::operator==(const Book &other) const
{
    return yearOfPublishing == other.yearOfPublishing &&
     (strcmp(title, other.title) == 0) &&
     (strcmp(author, other.author) == 0);
}
bool Book::operator<(const Book &other) const
{
    if(yearOfPublishing != other.yearOfPublishing) return yearOfPublishing < other.yearOfPublishing;
    
    short titleCmp = strcmp(title, other.title);
    if(titleCmp != 0) return titleCmp < 0;

    return strcmp(author, other.author) < 0;
}
std::ostream &operator<<(std::ostream & out, const Book &book)
{
    out << book.title  << '\n' 
        << book.author << '\n' 
        << book.genre  << '\n' 
        << book.pages  << '\n' 
        << book.yearOfPublishing;

    return out;
}

std::ostream& Book::binPrint(std::ostream& out)
{

    size_t titleLen = strlen(title) + 1;
    out.write( (char*) &titleLen , sizeof(size_t));
    out.write(title, titleLen);

    size_t authoeLen = strlen(author) + 1;
    out.write( (char*) &authoeLen, sizeof(size_t));
    out.write(author, authoeLen);

    size_t genreLen = strlen(genre) + 1;
    out.write( (char*) &genreLen, sizeof(size_t));
    out.write(genre, genreLen);

    out.write( (char*) &pages, sizeof(short));
    out.write( (char*) &yearOfPublishing, sizeof(short));

    out.flush();

    return out;
}

void Book::print()
{
    std::cout << *this;
}