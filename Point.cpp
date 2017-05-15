#include<iostream>
#include<utility>
#include<string>
#include"Point.hpp"

using namespace std;

Point::Point(string _name, pair<float, float> _coord){
    name=_name;
    coord=_coord;
}
string Point::getName(){
    return name;
}
string Point::getSpecifier(){
    return specifier;
}
pair<float,float> Point::getCoord(){
    return coord;
}
