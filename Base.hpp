#include"PlanOfFlight.hpp"
#include "Route.hpp"
#include "Plane.hpp"
#include <vector>
class Base{
public:
    PlanOfFlight makePlanOfFlight(std::vector <Route> vecRt,std::vector <Plane> vecPlane);
};
