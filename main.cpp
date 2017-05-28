#include <iostream>
#include <fstream>
#include <iterator>
#include "Point.hpp"
#include "ListOfPoint.hpp"
#include "Route.hpp"
#include "ListOfRoute.hpp"
#include "Plane.hpp"
#include "ListOfPlane.hpp"
#include "Flight.hpp"
#include "PlanOfFlight.hpp"
#include "Dispatcher.hpp"
#include "Base.hpp"
using namespace std;

int main()
{
    ListOfPlane p;
    ListOfPlane &pl=p;
    ListOfPoint poi;
    ListOfPoint &point=poi;
    ListOfRoute r;
    ListOfRoute &rt=r;
    Base base;
    base.LoadData(pl,rt,point);
    /*ifstream in("listPlane.txt");
    ListOfPlane pl;
    Plane p;
    vector<Plane> listPl;
    int qty=0;
    while(in >> p) {
        if(in.eof()) break;
        listPl.push_back(p);
        qty++;
    }
    pl.setPlane(listPl, listPl.size());
    in.close();

    in.open("listRoute.txt");
    ListOfRoute rt;
    Route r;
    vector<Route> listRt;
    qty=0;
    while(in >> r) {
        if(in.eof()) break;
        listRt.push_back(r);
        qty++;
    }
    rt.setRoute(listRt, listRt.size());
    in.close();


    in.open("listFlightPlan.txt");
    PlanOfFlight plan;
    in >> plan;
    plan.loadPlane(pl.getPlane());
    plan.loadRoute(rt.getRoute());
    //cout << plan << endl;
    in.close();

    in.open("flight.txt");
    Dispatcher disp(plan);
    Flight flight;
    while(in >> flight) {
        if(in.eof()) break;
        disp.setFlight(flight);
        disp.correctFlight();
    }
    //Route route = plan.getRoute();
    vector<Point> vecPoint = plan.getRoute().getInsidePoint();
    cout << "Маршрут: " << plan.getRoute().getName()<<endl;
    for(unsigned int i=0; i<vecPoint.size(); i++) {
        cout << vecPoint[i].getName()<<" ";
    }*/

    /*
    ifstream in("listRoute.txt");
    Route r;
    in >> r;
    r.generateVecEdge();
    r.calcDistance();
    cout << r <<endl;
*/

/*
     Flight fl;
    vector<Flight> listFl;
    int qty=0;
    while(in >> fl) {
        if(in.eof()) break;
        listFl.push_back(fl);
        qty++;
    }
    for(unsigned int i = 0; i<listFl.size(); i++)
        cout << listFl[i] << endl;
*/

   /*
    ifstream in("flight.txt");
    Flight fl, lf;
    vector<Flight> listFl;
    int qty=0;
    in >> fl;
    in >> lf;
    fl = lf;
    cout << fl << endl << endl << lf << endl;



    /*Plane r;

    ListOfPlane p;
    int len=0;
    vector<Plane> _listPlane;
    while(in >> r) {
        if(in.eof()) break;
        _listPlane.push_back(r);
        len++;
    }
    p.setPlane(_listPlane, len);
    for(unsigned int i = 0; i<p.getPlane().size(); i++)
        cout << p.getPlane()[i] << endl;
*/
}
