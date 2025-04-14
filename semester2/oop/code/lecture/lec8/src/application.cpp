#include <iostream>
#include "library.h"

int main()
{
	try{
		fmi::dynamic_array da(10);
		int a = da.at(10);
		a = 5;
		std::cout<<da.at(10);
	}
	catch(std::out_of_range& e)
	{
		std::cout << "Exeption " << e.what();
	}
}