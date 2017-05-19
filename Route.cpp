#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <fstream>
#include "Point.hpp"
#include "Route.hpp"
//#include "ListOfPoint.hpp"

using namespace std;

ostream& operator<< (ostream& out, Route& route)
{
    out << route.name;
    out << route.distance;
    int num = route.vecInsidePoint.size();
    out << num;
    for(int i = 0; i<num; i++) {
        out << route.vecInsidePoint[i] << endl;
    }
    copy(route.edgeList.begin(), route.edgeList.end(), ostream_iterator<int>(out, " "));
    out << endl;
    return out;
}

istream& operator>> (istream& in, Route& route)
{
    getline(in, route.name);
    in >> route.distance;
    int num;
    in >> num;
    for(int i=0; i<num; i++) {
        in >> route.vecInsidePoint[i];
        route.vecInsidePoint[i].defineSpecifier();
    }
    for(int i=1; i<route.vecInsidePoint.size()-1; i++) {
        in >> route.edgeList[i];
    }
    return in;
}


/*Point loadPoint(string _name, vector<Point> pointList)
{
    for(int i=0; i<pointList.size(); i++) {
        if(_name == pointList[i].getName()) {
            Point point = pointList[i];
            return point;
        }
    }
}*/

void Route::calcDistance()
{
    for(int i=0; i<edgeList.size(); i++) {
        distance+=edgeList[i];
    }
}
void Route::generateVecEdge()
{
    for(int i=0; i<vecInsidePoint.size()-1; i++) {
        edgeList.push_back(calcLengthOfEdge(vecInsidePoint[i], vecInsidePoint[i+1]));
    }
}

int calcLengthOfEdge(Point start, Point finish)
{
    //Подсчёт расстояния между двумя точками, округленого до целого
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

int Route::getDistance()
{
    return distance;
}