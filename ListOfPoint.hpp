#pragma once

#include <vector>
#include "Point.hpp"

class ListOfPoint{
private:
    std::vector<Point> vecPoint;
    unsigned int numbOfPoint;
public:
    void append();
    void remove();
    void setVecPoint(std::vector<Point> _vecP,unsigned int numb);
    std::vector<Point> getVecPoint();
    unsigned int getNumbPoint();
};
