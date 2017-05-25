#include <iostream>
#include <fstream>
#include <string>
#include "Plane.hpp"

using namespace std;

ostream& operator<< (ostream& out, Plane& plane)
{
    out << plane.name << " ";
    out << plane.topSpeed << " ";
    out << plane.topAltitude << " ";
    out << plane.topDistance << " ";
    return out;
}

istream& operator>> (istream& in, Plane& plane)
{
    in >> plane.name;
    in >> plane.topSpeed;
    in >> plane.topAltitude;
    in >> plane.topDistance;
    return in;
}

Plane Plane::operator = (const Plane &plane)
{
    if (&plane == this)
        return *this;
    (this->name = plane.name,
                  this->topSpeed = plane.topSpeed,
                  this->topAltitude = plane.topAltitude,
                  this->topDistance = plane.topDistance);
}


Plane::Plane()
{}

void Plane::setName(string _name)
{
    name = _name;
}

string Plane::getName(){
    return name;
}
int Plane::getTopSpeed(){
    return topSpeed;
}
int Plane::getTopAltitude(){
    return topAltitude;
}
int Plane::getTopDistance(){
    return topDistance;
}
