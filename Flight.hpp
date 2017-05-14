#pragma once

#include <utility>

class Flight {
private:
    int speed;
    int altitude;
    pair<float, float> coord;
    char typeOfCommunicate();

public:
    void setSpeed();
    void setAltitude();
    void setCoord();
    void getSpeed();
    void getAltitude();
    std::pair<float, float> getCoord();
};