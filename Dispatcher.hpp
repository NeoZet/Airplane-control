#pragma once

#include <string>
#include <utility>
#include "Flight.hpp"
#include "PlanOfFlight.hpp"

class Dispatcher{
private:
    std::string name;
    PlanOfFlight plan;
    Flight flight;
public:
    Dispatcher(PlanOfFlight _plan) : plan(_plan) {}
    void setFlight(Flight _flight);
    void correctFlight(int *dist, int *averSpeed);
    std::pair<int, int> recalcFlightTime(int *averSpeed);
    int *recalcDistance(int *dist);
    std::string findLocateOnMap();
};
