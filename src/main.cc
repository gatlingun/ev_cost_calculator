/*Launcher for EV Cost Calculator */

#include <iostream>
#include <memory>
#include "gas_vehicle.h"
#include "eletric_vehicle.h"

int main() {
    std::unique_ptr<GasVehicle> toyota_crown = std::make_unique<GasVehicle>(40.5, 4.10);
    std::unique_ptr<EletricVehicle> mustang_mache = std::make_unique<EletricVehicle>(3, 0.35);
    double mile_trip = 23.3;
    std::cout << "Cost for " << mile_trip << " trip in gas car: $" << toyota_crown->trip_cost(mile_trip) << std::endl;
    std::cout << "Cost for " << mile_trip << " trip in EV car: $" << mustang_mache->trip_cost(mile_trip) << std::endl;
    return 0;
}