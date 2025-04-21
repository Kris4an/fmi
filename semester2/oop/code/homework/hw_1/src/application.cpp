#include <iostream>
#include "registration_plate.h"
#include <cstring>

int main()
{
	
	registration_plate rp("A1234ZZ");

	std::cout<<rp;

	std::cin >> rp;
	std::cout<<rp;
}