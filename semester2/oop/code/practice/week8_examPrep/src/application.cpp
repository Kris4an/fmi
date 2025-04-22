#include <iostream>
#include <fstream>
#include "drone.h"

int main() {
	std::ofstream out("data.bin", std::ios::binary);
	double coords[] = {1,5,0.01,0.05,123,128};

	for(double d : coords) out.write((char*)&d, sizeof(d));

	out.close();

	Drone d1("data.bin", "volen_bolen");

	d1.printGeneratedPath();
}