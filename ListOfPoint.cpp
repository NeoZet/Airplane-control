#include <iostream>
#include <vector>
#include "ListOfPoint.hpp"
#include "Point.hpp"

using namespace std;

void ListOfPoint::setVecPoint(vector<Point> _vecP, unsigned int numb){
    vecPoint=_vecP;
    numbOfPoint=numb;
}
vector<Point> ListOfPoint::getVecPoint(){
    return vecPoint;
}
unsigned int ListOfPoint::getNumbPoint(){
    return numbOfPoint;
}
