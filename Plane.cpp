#include<iostream>
#include<string>
#include"Plane.hpp"

using namespace std;

Plane::Plane()
{}
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
