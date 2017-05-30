#include <iostream>
#include "Base.hpp"
#include <utility>
#include <string>
#include "PlanOfFlight.hpp"
#include <vector>
using namespace std;

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
   plan1.calcFlightTime();
   return plan1;
}
