#include <iostream>
#include <utility>
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


void Dispatcher::correctFlight()
{
    pair<int, int> time = flight.getTime();
    cout << "Время: " << time.first <<":"<<time.second<<endl;
    cout << "Скорость: "<< flight.getSpeed() <<
            " (Рекомендуемая: "<<plan.getRecSpeed() <<")"<< endl;
    cout << "Высота: "<<flight.getAltitude() <<
            " (Рекомендуемая: "<<plan.getRecAlt()<<")"<<endl;

    cout << endl<<"Сообщение диспетчера:"<<endl;
    if(flight.getSpeed() > plan.getRecSpeed()) {
        cout<<"Скорость превышает рекомендуемую! "
           <<"Понизьте скорость на "<<flight.getSpeed()-plan.getRecSpeed()<<" км/ч"<<endl;
    }

    else if(flight.getSpeed() < plan.getRecSpeed()) {
        cout<<"Скорость ниже рекомендуемой! "
           <<"Повысьте скорость на "<<plan.getRecSpeed()-flight.getSpeed()<<" км/ч"<<endl;
    }

    else cout << "Скорость в норме!"<<endl;

    if(flight.getAltitude() - plan.getRecAlt()>5) {
        cout<<"Высота превышает рекомендуемую! "
           <<"Понизьте высоту на "<<flight.getAltitude()-plan.getRecAlt()<<" км/ч"<<endl;
    }

    else if(plan.getRecSpeed()-flight.getSpeed()<5) {
        cout<<"Высота ниже рекомендуемой! "
           <<"Повысьте высоту на "<<plan.getRecAlt()-flight.getAltitude()<<" км/ч"<<endl;
    }

    else cout << "Высота в норме!"<<endl;
}