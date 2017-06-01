#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <utility>
#include <unistd.h>
#include <cstdlib>
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
    plan1.calcFlightTime();
    return plan1;
}

int Base::run()
{
    ListOfPlane listPl;
    ListOfPoint listPt;
    ListOfRoute listRt;
    LoadData(listPl, listRt, listPt);
    while(1) {
        system ("clear");
        cout << "***Airplane control***" << endl;
        cout << "Выберите действие: "  <<endl;
        cout << "-Задать полет [1]" <<endl;
        cout << "-Создать маршрут [2]"<<endl;
        cout << "-Добавить самолет [3]"<<endl;
        cout << "-Удалить маршрут [4]" <<endl;
        cout << "-Удалить самолет [5]" <<endl;
        cout << "Выход [0]"<<endl;
        cout << "Ввод: ";
        int key;
        cin >> key;
        switch(key) {
        case 1:
        {
            int keyRt;
            cout <<endl<< "Выберите маршрут:"<<endl;
            for(unsigned int i=0; i<listRt.getRoute().size(); i++) {
                cout <<"-"<<listRt.getRoute()[i].getName()<<" ["<<i+1<<"]"<<endl;
            }
            cout << "Ввод: ";
            cin >> keyRt;
            int keyPl;
            cout << endl<<"Выберите самолет:"<<endl;
            for(unsigned int i=0; i<listPl.getPlane().size(); i++) {
                cout <<"-"<<listPl.getPlane()[i].getName()<<" ["<<i+1<<"]"<<endl;
            }
            cout << "Ввод: ";
            cin >> keyPl;
            int keyTypeCom;
            PlanOfFlight plan;
            cout << endl<<"Выберите способ передачи данных:"<<endl;
            cout << "-Автоматический [1]"<<endl;
            cout << "-Ручной [2]"<<endl;
            cout << "Ввод: ";
            cin>>keyTypeCom;
            cout << endl;
            if(keyTypeCom == 1)
                plan.setTypeCommunicate('A');
            else if(keyTypeCom == 2)
                plan.setTypeCommunicate('M');
            ifstream in("listFlightPlan.txt");
            int var=0;
            while(var != keyRt) {
                in >> plan;
                var++;
            }
            plan.loadPlane(listPl.getPlane());
            plan.loadRoute(listRt.getRoute());
            plan.calcArriveTime();
            plan.calcFlightTime();
            in.close();

            string logFileName = plan.getRoute().getName()+".log";
            in.open(logFileName.c_str());
            Dispatcher disp(plan);
            Flight flight;
            int *averSpeed;
            int d = listRt.getRoute()[keyRt-1].getDistance();
            int *dist = &d;
            int aSpeed=0;
            int qty=0;
            int allSpeed=0;
            if(keyTypeCom == 1) {
                while(in >> flight) {
                    if(in.eof()) break;
                    qty++;
                    allSpeed+=flight.getSpeed();
                    aSpeed = (allSpeed/qty);
                    averSpeed = &aSpeed;
                    disp.setFlight(flight);
                    disp.correctFlight(dist, averSpeed);
                    //usleep(500000);
                }
            }
            else if(keyTypeCom == 2) {
                disp.setFlight(flight);
                disp.correctFlight(dist, averSpeed);
            }
            cout << "Посадка..."<<endl;
            usleep(2000000);
            pair<int, int> time = disp.recalcFlightTime(averSpeed);
            vector<Point> vecPoint = listRt.getRoute()[keyRt-1].getInsidePoint();
            qty = vecPoint.size();
            cout << plan.getRoute().getInsidePoint().size() << endl;
            cout <<"Время: "<<time.first<<":"<<time.second<<endl;
            cout << "Скорость: 0 км/ч"<<endl;
            cout << "Высота: 0 м" << endl;
            cout << "Оставшийся путь: 0 км"<<endl;
            cout << endl;
            cout << "Маршрут: " << listRt.getRoute()[keyRt-1].getName()<<endl;
            for(unsigned int i=0; i<vecPoint.size(); i++) {
                cout << vecPoint[i].getName()<<" ";
            }
            cout << endl;
            cout << "Для продолжения нажмите Enter"<<endl;
            getchar();
            getchar();
            break;
        }
        case 2:
            listRt.append(listPt.getVecPoint());
            SaveData(listPl, listRt, listPt);
            cout << "Для продолжения нажмите Enter"<<endl;
            getchar();
            getchar();
            break;
        case 3:
            listPl.append();
            SaveData(listPl, listRt, listPt);
            cout << "Для продолжения нажмите Enter"<<endl;
            getchar();
            getchar();
            break;
        case 4:
            listRt.remove();
            SaveData(listPl, listRt, listPt);
            cout << "Для продолжения нажмите Enter"<<endl;
            getchar();
            getchar();
            break;
        case 5:
            listPl.remove();
            SaveData(listPl, listRt, listPt);
            cout << "Для продолжения нажмите Enter"<<endl;
            getchar();
            break;
        case 0:
            return 0;
        }
    }

}