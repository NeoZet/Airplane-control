#include <iostream>
#include <fstream>
#include "Base.hpp"
#include <utility>
#include <string>
#include <vector>
using namespace std;

void Base::LoadData(ListOfPlane &pl, ListOfRoute &rt, ListOfPoint &point)
{
    ifstream in("listPlane.txt");
    Plane plane;
    vector<Plane> listPl;
    int qty=0;
    while(in>>plane)
    {
        if(in.eof())
            break;
        listPl.push_back(plane);
        qty++;
    }
    pl.setPlane(listPl,listPl.size());
    in.close();

    in.open("listRoute.txt");
    Route route;
    vector<Route> listRt;
    qty=0;
    while(in>>route)
    {
        if(in.eof())
            break;
        listRt.push_back(route);
        qty++;
    }
    rt.setRoute(listRt,listRt.size());
    in.close();

    in.open("listPoint.txt");
    Point p;
    vector<Point> listPoint;
    qty=0;
    while(in>>p)
    {
        if(in.eof())
            break;
        listPoint.push_back(p);
        qty++;
    }
    point.setVecPoint(listPoint,listPoint.size());
    in.close();
}

void Base::SaveData(ListOfPlane &pl, ListOfRoute &rt, ListOfPoint &point)
{
   int i;
   ofstream out("listPlane.txt");
   vector<Plane> vecPl=pl.getPlane();
   for(i=0;i<pl.getNumbPlane();i++)
       out<<vecPl[i]<<endl;
   out.close();

   out.open("listRoute.txt");
   vector<Route> vecRt=rt.getRoute();
   for(i=0;i<rt.getNumbRoute();i++)
      out<<vecRt[i]<<endl;
   out.close();

   out.open("listPoint.txt");
   vector<Point> vecPoi=point.getVecPoint();
   for(i=0;i<point.getNumbPoint();i++)
       out<<vecPoi[i]<<endl;
   out.close();
}

PlanOfFlight Base::makePlanOfFlight(vector<Route> vecRt,vector<Plane> vecPlane)
{
    PlanOfFlight plan;
    Plane plane;
    Route rt;
    string title,name;
    int recommendSpeed;
    int recommendAltitude;
    pair<int, int> departTime;
    char typeOfCommunicate;

    cout<<"Введите название маршрута"<<endl;
    getline(cin,title);
    rt.setName(title);
    plan.loadRoute(vecRt);

    cout<<"Введите название самолёта"<<endl;
    cin.ignore(1,'\n');
    getline(cin,name);
    plane.setName(name);
    plan.loadPlane(vecPlane);

    cout<<"Введите рекомендуемую скорость"<<endl;
    cin>>recommendSpeed;

    cout<<"Введите рекомендуемую высоту"<<endl;
    cin>>recommendAltitude;

    cout<<"Введите время вылета"<<endl;
    int hour,minuts;
    cout<<"Часы:";
    cin>>hour;
    cout<<endl;
    cout<<"Минуты:";
    cin>>minuts;
    cout<<endl;
    departTime=make_pair(hour,minuts);

    cout<<"Выбирите тип свзи"<<endl;
    cin>>typeOfCommunicate;

   PlanOfFlight plan1(title,rt,plane,departTime,typeOfCommunicate);
   return plan1;
}
