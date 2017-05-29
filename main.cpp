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
    Plane plane;
    Route route;
    Point point1;
    vector<Route> vecR=rt.getRoute();
    vector<Plane> vecPl=pl.getPlane();
    vector<Point> vecPoi=point.getVecPoint();
    unsigned int i;
    for( ; ; ){
    cout<<"1.Список саолётов,маршрутов,точек\n2.Добавить самолёт и точку\n3.Сохранить данные\n";
    cin>>i;
    switch (i) {
    case 1:
        cout<<"Route\n"<<endl;
         for(i=0;i<vecR.size();i++)
             cout<<vecR[i]<<endl<<endl;
         cout<<endl;
         cout<<"Plane\n"<<endl;
         for(i=0;i<vecPl.size();i++)
             cout<<vecPl[i]<<endl;
         cout<<endl;
         cout<<"Point\n"<<endl;
         for(i=0;i<vecPoi.size();i++)
             cout<<vecPoi[i]<<endl;
         cout<<endl;
        break;
     case 2:
        cout<<"Plane"<<endl;
        cin>>plane;
        vecPl.push_back(plane);
        cout<<"Point"<<endl;
        cin>>point1;
        vecPoi.push_back(point1);
        pl.setPlane(vecPl,vecPl.size());
        point.setVecPoint(vecPoi,vecPoi.size());
        /*cout<<"Route"<<endl;
        cin>>route;
        vecR.push_back(route);
        rt.setRoute(vecR,vecR.size());
        break;*/
     case 3:base.SaveData(pl,rt,point);
    default:
        break;
    }
    if(i==0)
        break;
   }
}
