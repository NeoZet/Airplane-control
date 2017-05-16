#pragma once

#include <string>
#include <vector>
#include <utility>
#include "Point.hpp"

class Route {
private:
    std::string name;
    std::pair<Point, Point> extrPoint;
    std::vector<Point> vecInsidePoint;
    std::vector<int> edgeList;
    int distance;

public:
    void calcDistance();
    void generateVecEdge();
    void setName(std::string _name);
    void setExtrPoint(std::pair<Point, Point> _extrPoint);
    void setInsidePoint(std::vector<Point> _vecInsidePoint);
    std::string getName();
    std::pair<Point, Point> getExtrPoint();
    std::vector<Point> getInsidePoint();
    std::vector<int> getEdgeList();
};