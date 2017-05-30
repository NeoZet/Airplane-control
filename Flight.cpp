#include <utility>
#include <fstream>
#include "Flight.hpp"

using namespace std;

ostream& operator<< (ostream& out, Flight& flight)
{
    out << flight.time.first<<" ";
    out << flight.time.second<<" ";
    out << flight.coord.first << " ";
    out << flight.coord.second << " ";
    out << flight.speed << " ";
    out << flight.altitude << " ";
    return out;
}

istream& operator>> (istream& in, Flight& flight)
{
    in >> flight.time.first;
    in >> flight.time.second;
    in >> flight.coord.first;
    in >> flight.coord.second;
    in >> flight.speed;
    in >> flight.altitude;
    return in;
}

Flight Flight::operator = (const Flight &flight)
{
    if (&flight == this)
        return *this;
    (this->speed = flight.speed,
                  this->altitude = flight.altitude,
                  this->coord = flight.coord,
                  this->time = flight.time);
}

/*void Flight::setSpeed()
{}

void Flight::setAltitude()
{}

void Flight::setCoord()
{}*/

int Flight::getSpeed()
{
    return speed;
}

int Flight::getAltitude()
{
    return altitude;
}

pair<float, float> Flight::getCoord()
{
    return coord;
}

pair<int, int> Flight::getTime()
{
    return time;
}
