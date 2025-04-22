#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "registration_plate.h"
#include "ucn.h"

class vehicle_register{
    std::map<registration_plate, ucn> vehicles;
public:
    vehicle_register();
    void registerVehicle(registration_plate, ucn);
    void deregisterVehicle(registration_plate);
    std::vector<registration_plate> owned_vehicles(ucn person) const;
    friend std::istream& operator>>(std::istream&, vehicle_register&);
    friend std::ostream& operator<<(std::ostream&, const vehicle_register&);
};