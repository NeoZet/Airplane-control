#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include "Point.hpp"

using namespace std;

ostream& operator<< (ostream& out, Point& point)
{
    out << point.name << " ";
    out << point.coord.first << " ";
    out << point.coord.second;
    return out;
}

istream& operator>> (istream& in, Point& point)
{
    in >> point.name;
    in >> point.coord.first;
    in >> point.coord.second;
    return in;
}

/*Point::Point(const Point& point) {
    name = point.name;
    coord = point.coord;
    specifier = point.specifier;
}*/

void Point::setName(std::string _name){
    name = _name;
}

void Point::setCoord(std::pair<float, float> _coord) {
    coord = _coord;
}

void Point::defineSpecifier() {
    specifier = 1;
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
