#include <iostream>
#include <vector>
#include "ListOfPlane.hpp"
#include "Plane.hpp"

using namespace std;

void ListOfPlane::setPlane(vector<Plane> _vecPlane,unsigned int numb){
    vecPlane=_vecPlane;
    numbOfPlane=numb;
}
vector<Plane> ListOfPlane::getPlane(){
    return vecPlane;
}
unsigned int ListOfPlane::getNumbPlane(){
    return numbOfPlane;
}
