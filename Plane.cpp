#include<iostream>
#include<string>
#include"Plane.hpp"

using namespace std;

Plane::Plane()
{}
Plane::Plane(string _name, int _topSpeed, int _topAltitude, int _topDistance)
{
    name=_name;
    topSpeed=_topSpeed;
    topAltitude=_topAltitude;
    topDistance=_topDistance;
}
string Plane::getName(){
    return name;
}
int Plane::getCruiseSpeed(){
    return topSpeed;
}
int Plane::getTopAltitude(){
    return topAltitude;
}
int Plane::getTopDistance(){
    return topDistance;
}
