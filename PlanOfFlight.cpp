#include <iostream>
#include <string>
#include <utility>
#include "PlanOfFlight.hpp"
#include "Route.hpp"
#include "Plane.hpp"

using namespace std;

PlanOfFlight::PlanOfFlight(string _name, Route _route, Plane _plane, pair<int, int> depTime, char typeCom)
{
    name=_name;
    route=_route;
    plane=_plane;
    departTime=depTime;
    typeOfCommunicate=typeCom;
}

void PlanOfFlight::calcFlightTime()
{}

string PlanOfFlight::getName()
{
    return name;
}

string PlanOfFlight::getRoute()
{
    return route.getName();
}

string PlanOfFlight::getPlane()
{
    return route.getName();
}

int PlanOfFlight::getRecSpeed()
{
    return recommendSpeed;
}

int PlanOfFlight::getRecAlt()
{
    return recommendAltitude;
}

int PlanOfFlight::getDistance()
{
    return flightDistance;
}

pair<int, int> PlanOfFlight::getDepartTime()
{
    return departTime;
}

pair<int, int> PlanOfFlight::getArrivTime()
{
    return arriveTime;
}

pair<int, int> PlanOfFlight::getFlightTime()
{
    return flightTime;
}

char PlanOfFlight::getTypeCommunicate()
{
    return typeOfCommunicate;
}
