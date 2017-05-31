#include "ListOfPlane.hpp"
#include "ListOfPoint.hpp"
#include "ListOfRoute.hpp"
#include "PlanOfFlight.hpp"
#include "Route.hpp"
#include "Plane.hpp"
#include <vector>
class Base{
public:
    void LoadData(ListOfPlane &pl,ListOfRoute &rt,ListOfPoint &point);
    void SaveData(ListOfPlane &pl,ListOfRoute &rt,ListOfPoint &point);
    PlanOfFlight makePlanOfFlight(std::vector <Route> vecRt,std::vector <Plane> vecPlane);
    int run();
};
