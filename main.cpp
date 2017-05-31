#include <iostream>
#include <fstream>
#include <iterator>
#include <unistd.h>
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
#include <sstream>

using namespace std;

int main()
{
    Base base;
    base.run();
    /*////////////////
    ifstream in("listPlane.txt");
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
    plan.calcArriveTime();
    plan.calcFlightTime();
    ofstream out("listFlightPlan.txt");
    out << plan << endl;
    plan.distance = r.getDistance();
    in.close();

    in.open("KBOS-KORD.log");
    Dispatcher disp(plan);
    Flight flight;
    int *averSpeed;
    int d = r.getDistance();
    int *dist = &d;
    int aSpeed=0;
    qty=0;
    int allSpeed=0;
    while(in >> flight) {
        if(in.eof()) break;
        qty++;
        allSpeed+=flight.getSpeed();
        aSpeed = (allSpeed/qty);
        averSpeed = &aSpeed;
        disp.setFlight(flight);       
        disp.correctFlight(dist, averSpeed);
        usleep(500000);
    }
    cout << "Посадка...";
    cout << endl;
    vector<Point> vecPoint = plan.getRoute().getInsidePoint();
    cout << "Маршрут: " << plan.getRoute().getName()<<endl;
    for(unsigned int i=0; i<vecPoint.size(); i++) {
        cout << vecPoint[i].getName()<<" ";
    }
    cout << endl;
   */
////////////////////////*/

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
