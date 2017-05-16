#pragma once

#include <string>
#include <utility>
#include "Route.hpp"
#include "Plane.hpp"

class PlanOfFlight {
private:
    std::string name;
    Route route;
    Plane plane;
    int recommendSpeed;
    int recommendAltitude;
    int flightDistance;
    std::pair<int, int> departTime;
    std::pair<int, int> arriveTime;
    std::pair<int, int> flightTime;
    char typeOfCommunicate;

public:
    PlanOfFlight(std::string _name, Route _route, Plane _plane, std::pair<int, int> depTime, char typeCom);
    void calcFlightTime();
    std::string getName();
    std::string getRoute();
    std::string getPlane();
    int getRecSpeed();
    int getRecAlt();
    int getDistance();
    std::pair<int, int> getDepartTime();
    std::pair<int, int> getArrivTime();
    std::pair<int, int> getFlightTime();
    char getTypeCommunicate();
};
