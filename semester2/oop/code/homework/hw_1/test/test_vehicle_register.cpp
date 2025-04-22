#include <sstream>
#include <string>
#include <vector>
#include "catch2/catch_all.hpp"
#include "vehicle_register.h"
#include "ucn.h"
#include "registration_plate.h"

TEST_CASE("vehile_register registerVehicle and operator<<")
{
    vehicle_register vr;

    vr.registerVehicle(registration_plate("AA1234BB"), ucn("0649034487"));

    std::stringstream str;

    str << vr;

    REQUIRE((str.str() == std::string("0649034487 AA1234BB\n")));
}

TEST_CASE("vehile_register deregisterVehile and owned_vehicle")
{
    SECTION("deregister registered vehicle")
    {
        vehicle_register vr;

        vr.registerVehicle(registration_plate("AA1234BB"), ucn("0649034487"));
        vr.deregisterVehicle(registration_plate("AA1234BB"));

        std::vector<registration_plate> v = vr.owned_vehicles(ucn("0649034487"));

        REQUIRE(v.empty());
    }
    SECTION("deregister unregistered vehicle")
    {
        vehicle_register vr;
        const registration_plate rp = registration_plate("AA1234BB");
        vr.registerVehicle(rp, ucn("0649034487"));
        REQUIRE_NOTHROW(vr.deregisterVehicle(registration_plate("A9876BB")));

        std::vector<registration_plate> v = vr.owned_vehicles(ucn("0649034487"));

        REQUIRE((v.size() == 1 && v.back() == rp));
    }
}