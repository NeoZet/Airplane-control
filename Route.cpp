#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <fstream>
#include "Point.hpp"
#include "Route.hpp"

using namespace std;

ostream& operator<< (ostream& out, Route& route)
{
    out << route.name << endl;
    out << route.distance << endl;
    int num = route.vecInsidePoint.size();
    out << num << endl;
    for(int i = 0; i<num; i++) {
        out << route.vecInsidePoint[i]<<endl;
    }
    copy(route.edgeList.begin(), route.edgeList.end(), ostream_iterator<int>(out, " "));
    return out;
}

istream& operator>> (istream& in, Route& route)
{
    getline(in, route.name);
    in >> route.distance;
    int num;
    in >> num;
    Point p;
    for(int i=0; i<num; i++) {
        in >> p;
        route.vecInsidePoint.push_back(p);
        route.vecInsidePoint[i].defineSpecifier();
    }
    int ed;
    for(unsigned int i=0; i<route.vecInsidePoint.size()-1; i++) {
        in >> ed;
        route.edgeList.push_back(ed);
    }
    return in;
}

void Route::calcDistance()
{
    distance = 0;
    for(unsigned int i=0; i<edgeList.size(); i++) {
        distance+=edgeList[i];
    }
}
void Route::generateVecEdge()
{
    vector<int>::iterator it = edgeList.begin();
    for(unsigned int i=0; i<vecInsidePoint.size()-1; i++) {
        //edgeList.push_back(calcLengthOfEdge(vecInsidePoint[i], vecInsidePoint[i+1]));
        edgeList[i]=(calcLengthOfEdge(vecInsidePoint[i], vecInsidePoint[i+1]));
    }
}

int Route::calcLengthOfEdge(Point start, Point finish)
{
    pair<float, float> coord;
    coord = start.getCoord();
    float lotitude1=coord.first;
    float longitude1=coord.second;
    coord = finish.getCoord();
    float lotitude2=coord.first;
    float longitude2=coord.second;
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
    length *= 6371;
    int len = static_cast<int>(ceil(100*length) / 100.0);
    return len;
}

void Route::setName(string _name)

{
    name = _name;
}

void Route::setInsidePoint(std::vector<Point> _vecInsidePoint)
{
    vecInsidePoint = _vecInsidePoint;
}

string Route::getName()
{
    return name;
}

vector<Point> Route::getInsidePoint()
{
    return vecInsidePoint;
}

vector<int> Route::getEdgeList()
{
    return edgeList;
}

int Route::getDistance()
{
    return distance;
}