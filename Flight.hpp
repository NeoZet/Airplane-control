#pragma once

#include <utility>

class Flight {
private:
    int speed;
    int altitude;
    std::pair<float, float> coord;
    char typeOfCommunicate();

public:
    void setSpeed();
    void setAltitude();
    void setCoord();
    int getSpeed();
    int getAltitude();
    std::pair<float, float> getCoord();

    friend std::ostream& operator<< (std::ostream& out, Flight& flight);
    friend std::istream& operator<< (std::istream& in, Flight& flight);
};