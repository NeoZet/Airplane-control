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

Plane::Plane()
{}
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
