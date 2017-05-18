#include <utility>
#include "Flight.hpp"

using namespace std;

void Flight::setSpeed()
{}

void Flight::setAltitude()
{}

void Flight::setCoord()
{}

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
