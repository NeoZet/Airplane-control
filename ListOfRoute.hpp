#pragma once

#include <vector>
#include "Route.hpp"
#include "Point.hpp"

class ListOfRoute {
private:
      std::vector<Route> vecRoute;
      unsigned int numbOfRoute;
public:
      void append(std::vector<Point> vecAllPoint);
      void remove();
      std::vector<Point> loadInsPoint(std::vector<Point> vecInsPt, std::vector<Point> vecAllPoint);
      void setRoute(std::vector<Route> _vecRoute, unsigned int numb);
      std::vector<Route> getRoute();
      unsigned int getNumbRoute();
};