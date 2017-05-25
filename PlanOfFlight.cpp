#include <iostream>
#include <string>
#include <utility>
#include "PlanOfFlight.hpp"
#include "Route.hpp"
#include "Plane.hpp"

using namespace std;

ostream& operator<< (ostream& out, PlanOfFlight& plan)
{
    out << plan.name << endl;
    out << plan.route<< endl;
    out << plan.plane<< endl;
    out << plan.recommendSpeed<< endl;
    out << plan.recommendAltitude<< endl;
    out << plan.departTime.first<< ":";
    out << plan.departTime.second<< endl;
    out << plan.arriveTime.first<<":";
    out << plan.arriveTime.second<<endl;
    out << plan.flightTime.first <<":"<<plan.flightTime.second;
    return out;
}


istream& operator>> (istream& in, PlanOfFlight& plan)
{
    string str;
    in >> plan.name;
    in >> str;
    plan.route.setName(str);
    in >> str;
    plan.plane.setName(str);
    in >> plan.recommendSpeed;
    in >> plan.recommendAltitude;
    in >> plan.departTime.first;
    in >> plan.departTime.second;
    in >> plan.arriveTime.first;
    in >> plan.arriveTime.second;
    plan.calcFlightTime();
    return in;
}

/*PlanOfFlight PlanOfFlight::operator = (const PlanOfFlight &plan)
{
    if (&plan == this)
        return *this;
    //(this->name = plan.name
            //this->route = plan.route,
           // this->plane = plan.plane,
            //this->recommendSpeed = plan.recommendSpeed,
            //this->recommendAltitude = plan.recommendAltitude,
            //this->departTime = plan.departTime,
            //this->arriveTime = plan.arriveTime,
            //this->flightTime = plan.flightTime);
}
*/


void PlanOfFlight::loadRoute(vector<Route> vecRt)
{
    for(unsigned int i=0; i<vecRt.size(); i++) {
        if(route.getName() == vecRt[i].getName()) {
            route = vecRt[i];
        }
    }
}

void PlanOfFlight::loadPlane(vector<Plane> vecPln)
{
    for(unsigned int i=0; i<vecPln.size(); i++) {
        if(plane.getName() == vecPln[i].getName()) {
            plane = vecPln[i];
        }
    }
}


void PlanOfFlight::calcFlightTime()
{
    int as, bs;
    flightTime.first = 23;
    flightTime.second = 60;
    as = (arriveTime.first*60 + arriveTime.second) - (departTime.first*60+departTime.second);
    if(as<0) {
        bs = as/60;
        flightTime.first += bs;
        as -= 60*bs;
        flightTime.second += as;
    }
    else {
        bs = as/60;
        flightTime.first = bs;
        as -= 60*bs;
        flightTime.second = as;
    }
}

string PlanOfFlight::getName()
{
    return name;
}

Route PlanOfFlight::getRoute()
{
    return route;
}

Plane PlanOfFlight::getPlane()
{
    return plane;
}

int PlanOfFlight::getRecSpeed()
{
    return recommendSpeed;
}

int PlanOfFlight::getRecAlt()
{
    return recommendAltitude;
}

/*int PlanOfFlight::getDistance()
{
    return flightDistance;
}*/

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

char PlanOfFlight::setTypeCommunicate(char type)
{
    typeOfCommunicate = type;
}