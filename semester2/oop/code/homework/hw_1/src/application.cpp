#include <iostream>
#include <vector>
#include <cstring>
#include "registration_plate.h"
#include "ucn.h"
#include "vehicle_register.h"


int main()
{
	registration_plate rp1("A1234BB");
	registration_plate rp2("BB1234HH");
	std::cout << rp2 << " ";
	std::cout << rp1.to_string() << " < " << rp2.to_string() << " -> " << (rp1 < rp2) << std::endl;
	std::cin >> rp1;
	std::cout << rp1 << " == " << rp2 << " -> " << (rp1 == rp2) << std::endl;

	ucn egn("0847038794");
	std::cout << "Person with ucn " << egn.to_string() << " is born on " 
		<< egn.day() << "/" << egn.month() << "/" << egn.year() << " in "
		<< egn.region() << std::endl;
	std::cin >> egn;
	std::cout << egn << std::endl;

	vehicle_register vr;

	vr.registerVehicle(rp1, egn);
	vr.registerVehicle(rp2, egn);
	std::cout << vr;
	std::cin >> vr;
	std::cout << vr;
	vr.deregisterVehicle(rp2);
	std::vector<registration_plate> v = vr.owned_vehicles(egn);

	for(const auto& vh : v) std::cout << vh << std::endl;
}