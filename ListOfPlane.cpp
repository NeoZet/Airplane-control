#include<iostream>
#include"ListOfPlane.hpp"
#include<vector>

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
