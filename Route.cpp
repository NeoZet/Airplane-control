#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Route.hpp"

using namespace std;

void Route::calcDistance();
void Route::generateVecEdge();

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

