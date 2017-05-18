#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Route.hpp"

using namespace std;

void Route::generateVecEdge();

void Route::calcDistance()

{
    float lotitude1,lotitude2,longitude1,longitude2;//широта 1,широта 2,долгота 1,долгота 2;
       cout<<"Введите координаты"<<endl;
       cin>>lotitude1>>longitude1;
       cin>>lotitude2>>longitude2;
       lotitude1=(lotitude1*M_PI)/180;//перевод в радианы;
       lotitude2=(lotitude2*M_PI)/180;//перевод в радианы;
       longitude1=(longitude1*M_PI)/180;//перевод в радианы;
       longitude2=(longitude2*M_PI)/180;//перевод в радианы;
       float length;//длина самого расстояния
       float c1,c2,s1,s2,delta,cdelta,sdelta,x,y;
       s1=sin(lotitude1);//синус широты 1;
       s2=sin(lotitude2);//синус широты 2;
       c1=cos(lotitude1);//косинус широты 1;
       c2=cos(lotitude2);//косинус широты 2;
       delta=longitude2-longitude1;//разница долгот;
       cdelta=cos(delta);//косинус разницы;
       sdelta=sin(delta);//синус разинцы;
       y=sqrt(pow(c2*sdelta,2)+pow(c1*s2-s1*c2*cdelta,2));//формула;
       x=(s1*s2+c1*c2*cdelta);//формула;
       length=atan2(y,x);
       cout<<"Расстояние в радиaнах:"<<length<<endl;
       length=length*6371;
       cout<<"Расстояние в километраx:"<<ceil(100*length) / 100.0<<endl;
}

void Route::setName(string _name)

{
    name = _name;
}
void Route::setExtrPoint(pair<Point, Point> _extrPoint)

{
    extrPoint = _extrPoint;
}

void Route::setInsidePoint(std::vector<Point> _vecInsidePoint)
{
    vecInsidePoint = _vecInsidePoint;
}

string Route::getName()
{
    return name;
}

pair<Point, Point> Route::getExtrPoint()
{
    return extrPoint;
}

vector<Point> Route::getInsidePoint()
{
    return vecInsidePoint;
}

vector<int> Route::getEdgeList()
{
    return edgeList;
}

