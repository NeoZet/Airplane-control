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
    //int flightDistance;
    std::pair<int, int> departTime;
    std::pair<int, int> arriveTime;
    std::pair<int, int> flightTime;
    char typeOfCommunicate;

public:
    PlanOfFlight() {}
    PlanOfFlight(std::string _name, Route _route, Plane _plane, std::pair<int, int> depTime, char typeCom)
        : name(_name), route(_route), plane(_plane), departTime(depTime), typeOfCommunicate(typeCom) {}
    void calcFlightTime();
    void loadRoute(std::vector<Route> vecRt);
    void loadPlane(std::vector<Plane> vecPln);
    std::string getName();
    Route getRoute();
    Plane getPlane();
    int getRecSpeed();
    int getRecAlt();
   // int getDistance();
    std::pair<int, int> getDepartTime();
    std::pair<int, int> getArrivTime();
    std::pair<int, int> getFlightTime();
    char getTypeCommunicate();
    char setTypeCommunicate(char type);

    PlanOfFlight operator = (const PlanOfFlight &plan);

    friend std::ostream& operator<< (std::ostream& out, PlanOfFlight& plan);
    friend std::istream& operator>> (std::istream& in, PlanOfFlight& plan);
};
