#include <iostream>
#include <utility>
#include <string>
#include "Dispatcher.hpp"
#include "Flight.hpp"
#include "PlanOfFlight.hpp"

using namespace std;

/*void Dispatcher::setPlanOfFlight(PlanOfFlight _plan)
{
    plan = _plan;
}*/

void Dispatcher::setFlight(Flight _flight)
{
    flight = _flight;
}

int* Dispatcher::recalcDistance(int *dist)//pair<int, int> _time, int _speed, int fullDist)
{
    pair<int, int> _time = flight.getTime();
    int NowTime = _time.first*60 + _time.second;
    int ArrTime = NowTime-1;
    int time = NowTime - ArrTime;
    //cout << endl<<"TIME "<<time<<endl<<endl;
    float speed = static_cast<float>(flight.getSpeed());
    speed /= 60;
    int passedDistance = speed*time;
    //cout << endl<<"DIST "<<passedDistance<<endl<<plan.distance<<endl;
    *dist -= passedDistance;
    return dist;
}

pair<int,int> Dispatcher::recalcFlightTime(int *averSpeed)//int dist, int _speed)
{
    float speed = static_cast<float>(*averSpeed);
    speed /= 60;
    int time = plan.getRoute().getDistance()/speed;
   // cout << endl<<"TIME "<<*averSpeed<<endl<<endl;
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

/*string Dispatcher::findLocateOnMap()
{
    string str;
    int n=0;
    for(int i=0; i<plan.getRoute().getInsidePoint().size()-1; i++) {
        if(plan.getRoute().getInsidePoint()[i].getCoord().first == flight.getCoord().first && (plan.getRoute().getInsidePoint()[i].getCoord().second == flight.getCoord().second)) {
            n=i;
            return plan.getRoute().getInsidePoint()[i].getName();
        }
        else str = plan.getRoute().getInsidePoint()[n].getName()+"->"+plan.getRoute().getInsidePoint()[n+1].getName();
    }
    return str;
}
*/

void Dispatcher::correctFlight(int *dist, int *averSpeed)
{
    pair<int, int> time = flight.getTime();
    cout << "Время: " << time.first <<":"<<time.second<<endl;
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
    int *distance=recalcDistance(dist);
    cout << "Оставшийся путь: "<<*dist<<" км"<<endl;
    time = recalcFlightTime(averSpeed);
    cout << "Время прибытия:"<<endl<<"-По расписанию: "<<plan.getArrivTime().first<<":"<<plan.getArrivTime().second<<endl
         <<"-Рассчетное: "<< time.first<<":"<<time.second<<endl<<endl;
//    cout << findLocateOnMap() << endl << endl;
}
