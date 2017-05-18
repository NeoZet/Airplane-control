#pragma once

#include <vector>
#include "Route.hpp"

class ListOfRoute {
private:
      std::vector<Route> vecRoute;
      unsigned int numbOfRoute;
public:
      void append();
      void remove();
      void setRoute(std::vector<Route> _vecRoute, unsigned int numb);
      std::vector<Route> getRoute();
      unsigned int getNumbRoute();
};