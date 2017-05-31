#include <iostream>
#include <vector>
#include <string>
#include "Route.hpp"
#include "Point.hpp"
#include "ListOfRoute.hpp"

using namespace std;

void ListOfRoute::append(vector<Point> vecAllPoint)
{
    string name;
    Point point;
    vector<Point> vecInsPt;
    int numbOfInsPoint=0;
    cout <<"Введите название маршрута (начальная точка-конечная точка): ";
    cin >> name;
    cout << "Введите точки маршрута (первая-точка отправления, последняя-точка прибытия)"<<endl<<"(Введите 's', чтобы завершить ввод): "<<endl;
    string pointName;
    for(int i=0;;i++) {
        cin >> pointName;
        if(pointName == "s") break;
        for(int j=0; j<vecAllPoint.size(); j++) {
            if(pointName == vecAllPoint[j].getName()) {
                point.setName(pointName);
                vecInsPt.push_back(point);
                numbOfInsPoint++;
                break;
            }
            else if(j==vecAllPoint.size()-1)
                cout << "Ошибка ввода! Точка не найдена!"<<endl;
        }
    }
    vecInsPt = loadInsPoint(vecInsPt, vecAllPoint);
    Route route;
    route.setName(name);
    route.setInsidePoint(vecInsPt);
    route.generateVecEdge();
    route.calcDistance();
    vecRoute.push_back(route);
    numbOfRoute++;
    cout << "Маршрут добавлен!"<<endl;
}

void ListOfRoute::remove()
{
    string name;
    cout << "Введите название маршрута: ";
    cin >> name;
    for(unsigned int i=0; i<vecRoute.size(); i++) {
        if(vecRoute[i].getName() == name) {
            vecRoute.erase(vecRoute.begin()+i);
            numbOfRoute--;
            cout << "Маршрут удален" << endl;
            break;
        }
        else if(i == vecRoute.size()-1)
            cout << "Ошибка! Маршрут не найден!" <<endl;
    }
}

vector<Point> ListOfRoute::loadInsPoint(vector<Point> vecInsPoint, vector<Point> vecAllPoint)
{
    for(unsigned int i=0; i<vecInsPoint.size(); i++) {
        for(unsigned int j=0; j<vecAllPoint.size(); j++) {
            if(vecInsPoint[i].getName() == vecAllPoint[j].getName()) {
                vecInsPoint[i].setCoord(vecAllPoint[j].getCoord());
                break;
            }
        }
    }
    return vecInsPoint;
}

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