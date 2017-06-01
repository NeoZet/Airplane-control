#pragma once

#include <string>
#include <vector>
#include <utility>
#include "Point.hpp"

class Route {
private:
    std::string name;
    int distance;
    std::vector<Point> vecInsidePoint;
    std::vector<int> edgeList;

public:
    int calcLengthOfEdge(Point start, Point finish);
    void calcDistance();
    void generateVecEdge();
    void setName(std::string _name);
    void setInsidePoint(std::vector<Point> _vecInsidePoint);
    std::string getName();
    std::vector<Point> getInsidePoint();
    std::vector<int> getEdgeList();
    int getDistance();

    //friend Point loadPoint(std::string _name);
    Route &operator =(const Route &route);

    friend std::ostream& operator<< (std::ostream& out, Route& route);
    friend std::istream& operator>> (std::istream& in, Route& route);
};