#pragma once

#include <vector>
#include "ListOfPlane.hpp"
#include "Plane.hpp"

class ListOfPlane{
private:
    std::vector<Plane> vecPlane;
    unsigned int numbOfPlane;
public:
    void append();
    void remove();
    void setPlane(std::vector<Plane> _vecPlane, unsigned int numb);
    std::vector<Plane> getPlane();
    unsigned int getNumbPlane();
};
