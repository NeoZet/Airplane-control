#include<iostream>
#include"ListOfPoint.hpp"
#include<vector>

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
