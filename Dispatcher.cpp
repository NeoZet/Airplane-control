#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <sstream>
#include "Dispatcher.hpp"
#include "Flight.hpp"
#include "PlanOfFlight.hpp"

using namespace std;

void Dispatcher::setFlight(Flight _flight)
{
    flight = _flight;
}

void Dispatcher::recalcDistance(int *dist)
{
    pair<int, int> _time = flight.getTime();
    int NowTime = _time.first*60 + _time.second;
    int ArrTime;
    if(plan.getTypeCommunicate()=='A')
        ArrTime= NowTime-1;
    else if(plan.getTypeCommunicate() == 'M')
        ArrTime = NowTime-15;
    int time = NowTime - ArrTime;
    float speed = static_cast<float>(flight.getSpeed());
    speed /= 60;
    int passedDistance = speed*time;
    *dist -= passedDistance;
}

pair<int,int> Dispatcher::recalcFlightTime(int *averSpeed)
{
    float speed = static_cast<float>(*averSpeed);
    speed /= 60;
    int time = plan.getRoute().getDistance()/speed;
    int as = time/60;
    int bs = time - as*60;
    pair<int, int> newTime;
    newTime.first = plan.getDepartTime().first+as;
    newTime.second = plan.getDepartTime().second+bs;
    if(newTime.first>=24) {
        newTime.first-=24;
    }
    if(newTime.second>=60) {
        newTime.second-=60;
    }
    return newTime;
}

string Dispatcher::findLocateOnMap()
{
    string str="->";
    int n=0;
    for(int i=0; i<plan.getRoute().getInsidePoint().size()-1; i++) {
        if(plan.getRoute().getInsidePoint()[i].getCoord().first == flight.getCoord().first && (plan.getRoute().getInsidePoint()[i].getCoord().second == flight.getCoord().second)) {
            n=i;
            str = plan.getRoute().getInsidePoint()[i].getName();
        }
    }
    return str;
}

void Dispatcher::correctFlight(int *dist, int *averSpeed)
{
    if(plan.getTypeCommunicate() == 'A') {
        pair<int, int> time = flight.getTime();
        cout << "Время: " << time.first <<":"<<time.second<<endl;
        cout << "Координаты (широта/долгота): "<<flight.getCoord().first<<" "<<flight.getCoord().second<<" ("<<findLocateOnMap()<<")"<<endl;
        cout << "Скорость: "<< flight.getSpeed() << " км/ч"<<" (Рекомендуемая: "<<plan.getRecSpeed() <<" км/ч)"<< endl;
        cout << "Высота: "<<flight.getAltitude() <<" м"<<" (Рекомендуемая: "<<plan.getRecAlt()<<" м)"<<endl;

        cout <<"Сообщение диспетчера:"<<endl;
        if(flight.getSpeed() > plan.getRecSpeed()) {
            cout<<"Скорость превышает рекомендуемую на "<<flight.getSpeed()-plan.getRecSpeed()<<" км/ч"<<endl;
        }
        else if(flight.getSpeed() < plan.getRecSpeed()) {
            cout<<"Скорость ниже рекомендуемой на "<<plan.getRecSpeed()-flight.getSpeed()<<" км/ч"<<endl;
        }
        else cout << "Скорость в норме!"<<endl;

        if(plan.getRecAlt() - flight.getAltitude()<0) {
            cout<<"Высота превышает рекомендуемую на "<<flight.getAltitude()-plan.getRecAlt()<<" м"<<endl;
        }
        else if(plan.getRecAlt()-flight.getAltitude()>0) {
            cout<<"Высота ниже рекомендуемой на "<<plan.getRecAlt()-flight.getAltitude()<<" м"<<endl;
        }
        else
            cout << "Высота в норме!"<<endl;
        recalcDistance(dist);
        cout << "Оставшийся путь: "<<*dist<<" км"<<endl;
        time = recalcFlightTime(averSpeed);
        cout << "Время прибытия:"<<endl<<"-По расписанию: "<<plan.getArrivTime().first<<":"<<plan.getArrivTime().second<<endl
             <<"-Рассчетное: "<< time.first<<":"<<time.second<<endl<<endl;
    }

    if(plan.getTypeCommunicate()=='M') {
        vector<Flight> vecFlight;
        int quantOfMessage = (plan.getFlightTime().first*60+plan.getFlightTime().second)/15;
        int speed;
        int altitude;
        pair<float, float> coord;
        pair<int, int> time = plan.getDepartTime();
        int qty = 0;
        int allSpeed = 0;
        int aSpeed = 0;
        for(int i=0; i<quantOfMessage; i++) {
            qty++;
            time.second+=15;
            if(time.second >= 60) {
                time.first++;
                time.second-=60;
            }
            if(time.first>=24) {
                time.first-=24;
            }
            flight.setTime(time);
            cout << "Время: "<<flight.getTime().first<<":"<<flight.getTime().second<<endl;
            cout << "Введите данные самолета:"<<endl;
            cout << "Координаты:"<<endl<<"-широта: ";
            cin >> coord.first;
            cout <<"-долгота: ";
            cin >>coord.second;
            flight.setCoord(coord);
            cout << "Скорость: ";
            cin >> speed;
            flight.setSpeed(speed);
            cout << "Высота: ";
            cin >> altitude;
            flight.setAltitude(altitude);
            vecFlight.push_back(flight);
            cout <<endl<<"Сообщение диспетчера:"<<endl;
            if(flight.getSpeed() > plan.getRecSpeed()) {
                cout<<"Скорость превышает рекомендуемую на "<<flight.getSpeed()-plan.getRecSpeed()<<" км/ч"<<endl;
            }
            else if(flight.getSpeed() < plan.getRecSpeed()) {
                cout<<"Скорость ниже рекомендуемой на "<<plan.getRecSpeed()-flight.getSpeed()<<" км/ч"<<endl;
            }
            else cout << "Скорость в норме!"<<endl;

            if(plan.getRecAlt() - flight.getAltitude()<0) {
                cout<<"Высота превышает рекомендуемую на "<<flight.getAltitude()-plan.getRecAlt()<<" м"<<endl;
            }
            else if(plan.getRecAlt()-flight.getAltitude()>0) {
                cout<<"Высота ниже рекомендуемой на "<<plan.getRecAlt()-flight.getAltitude()<<" м"<<endl;
            }
            else
                cout << "Высота в норме!"<<endl;
            allSpeed += flight.getSpeed();
            aSpeed = (allSpeed/qty);
            averSpeed = &aSpeed;
            recalcDistance(dist);
            cout << "Оставшийся путь: "<<*dist<<" км"<<endl;
            pair<int, int> newDepartTime = recalcFlightTime(averSpeed);
            cout << "Время прибытия:"<<endl<<"-По расписанию: "<<plan.getArrivTime().first<<":"<<plan.getArrivTime().second<<endl
                 <<"-Рассчетное: "<< newDepartTime.first<<":"<<newDepartTime.second<<endl<<endl;
        }
        qty = 0;
        string numb;
        ofstream out;
        ifstream in;
        //ostringstream ss;
        //in.open((plan.getRoute().getName()+"_"+str+".log").c_str());
        for(int i=0;;i++){
            in.open((plan.getRoute().getName()+"_"+numb+".log").c_str());
            if(in) {
                //qty++;
                ostringstream ss;
                ss<<i;
                numb = ss.str();
                cout <<endl<< numb << endl;
                in.close();
            }
            else break;
        }
        //ss<<qty;
        //ss>>str;
        out.open((plan.getRoute().getName()+"_"+numb+".log").c_str());
        for(unsigned int i=0; i<vecFlight.size(); i++) {
            out << vecFlight[i] << endl;
        }
    }
}