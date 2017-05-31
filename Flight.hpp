#pragma once

#include <utility>
#include <fstream>

class Flight {
private:
    int speed;
    int altitude;
    std::pair<float, float> coord;
    std::pair<int, int> time;
    char typeOfCommunicate();

public:
    void setSpeed(int _speed);
    void setAltitude(int _altitude);
    void setCoord(std::pair<float, float> _coord);
    void setTime(std::pair<int, int> _time);
    int getSpeed();
    int getAltitude();
    std::pair<float, float> getCoord();
    std::pair<int, int> getTime();

    Flight operator = (const Flight &flight);

    friend std::ostream& operator<< (std::ostream& out, Flight& flight);
    friend std::istream& operator>> (std::istream& in, Flight& flight);

};