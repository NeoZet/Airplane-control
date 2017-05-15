#include <vector>
#include "Route.hpp"
#include "ListOfRoute.hpp"

using namespace std;

void ListOfRoute::append();
void ListOfRoute::remove();

void ListOfRoute::setRoute(vector<Route> _vecRoute, unsigned int numb)
{
    vecRoute = _vecRoute;
    numbOfRoute = numb;
}

vector<Route> ListOfRoute::getRoute()
{
    return vecRoute;
}

unsigned int ListOfRoute::getNumbRoute()
{
    return numbOfRoute;
}