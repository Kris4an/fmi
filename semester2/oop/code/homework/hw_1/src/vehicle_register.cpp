#include <stdexcept>
#include <cstring>
#include "vehicle_register.h"
#include "ucn.h"
#include "registration_plate.h"

vehicle_register::vehicle_register(){}

void vehicle_register::registerVehicle(registration_plate registration, ucn owner)
{
    if (!vehicles.insert({registration, owner}).second)
        throw std::invalid_argument("Registration is already added");
}

void vehicle_register::deregisterVehicle(registration_plate registration)
{
    vehicles.erase(registration);
}

std::vector<registration_plate> vehicle_register::owned_vehicles(ucn person) const
{
    std::vector<registration_plate> plates;

    for (const auto &[rp, ucn] : vehicles)
    {
        if (ucn == person)
            plates.push_back(rp);
    }

    return plates;
}

std::istream &operator>>(std::istream &inStream, vehicle_register &vr)
{
    char egn[11];
    char rp[9];

    inStream >> egn >> rp;

    vr.vehicles.insert({registration_plate(rp), ucn(egn)});

    return inStream;
}
std::ostream &operator<<(std::ostream &outStream, const vehicle_register &vr)
{
    for (const auto &[rp, ucn] : vr.vehicles)
    {
        outStream << ucn << " " << rp << '\n';
    }

    return outStream;
}