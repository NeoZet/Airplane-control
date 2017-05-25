#pragma once

#include <string>
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
    void correctFlight();
   // void setPlanOfFlight(PlanOfFlight _plan);
};
