#include <iostream>
#include <vector>
#include "ListOfPoint.hpp"
#include "Point.hpp"

using namespace std;

void ListOfPoint::setVecPoint(vector<Point> _vecP, unsigned int numb){
    vecPoint=_vecP;
    numbOfPoint=numb;
}
vector<Point> ListOfPoint::getVecPoint(){
    return vecPoint;
}
unsigned int ListOfPoint::getNumbPoint(){
    return numbOfPoint;
}

void ListOfPoint::appened() 
{
    Point point;
    string str;
    try {
    cout << "Введите название точки:\n (В виде KXXX - если аэропорт)\n(В виде XXXXX - если точка промежуточная): ";
    cin.ignore(1,'\n');
    getline(cin, str);
    for(int i=0; i<numbOfPoint; i++) {
        if(str==vecPoint[i].getName())
        throw 1;
    }

    vecPoint.push_back(point);
    numbOfPoint++;
    cout << "Друг Добавлен!"<<endl;
    }
    catch(int err) {
    cout << "Ошибка! Человек уже существует!" <<endl;
    }

}
