#include <iostream>
#include <fstream>
#include "library.h"
#include "book.h"

int main(int argc, char* argv[])
{
	Library lib;
	lib.addBook(Book("Discrete structures", "M. M.", "comedy", 600, 2025));
	lib.addBook(Book("Design and analysis of algorithms", "M. M.", "comedy", 1100, 2025));

	std::ofstream oFile("../testBook.bin", std::ios::out | std::ios::binary);

	Book b("DAA", "MM", "comedy", 1100, 2025);
	b.binPrint(oFile);
	oFile.close();

	lib.saveToFile("../lib.txt");
	//std::cout << lib;
}