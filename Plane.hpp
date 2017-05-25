#pragma once

#include <string>
#include <fstream>

class Plane{
private:
    std::string name;
    int topSpeed;
    int topAltitude;
    int topDistance;
public:
    Plane();
    Plane(std::string _name,int _topSpeed,int _topAltitude,int _topDistance)
        : name(_name), topSpeed(_topSpeed), topAltitude(_topAltitude), topDistance(_topDistance) {}
    void setName(std::string _name);
    std::string getName();
    int getTopAltitude();
    int getTopSpeed();
    int getTopDistance();

    Plane operator = (const Plane &plane);

    friend std::ostream& operator<< (std::ostream& out, Plane& plane);
    friend std::istream& operator>> (std::istream& in, Plane& plane);
};
