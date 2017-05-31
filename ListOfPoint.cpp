#include <iostream>
#include <vector>
#include "ListOfPoint.hpp"
#include "Point.hpp"
#include <utility>

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

void ListOfPoint::append()
{
    string str;
    pair<float,float> coord;
    try {
    cout << "Введите название точки:\n (В виде KXXX - если аэропорт)\n(В виде XXXXX - если точка промежуточная): ";
    cin.ignore(1,'\n');
    getline(cin, str);
    cout<<"Введите координаты точки:"<<endl<<"Широта:";
    cin>>coord.first;
    cout<<"Долгота:";
    cin>>coord.second;
    for(unsigned int i=0; i<numbOfPoint; i++) {
        if(str==vecPoint[i].getName())
        throw 1;
    }
    Point point(str,coord);
    vecPoint.push_back(point);
    numbOfPoint++;
    cout << "Точка добавлена!"<<endl;
    }
    catch(int err) {
    cout << "Ошибка! Точка уже существует!" <<endl;
    }
}

void ListOfPoint::remove(){
    string poi;
    int flag,n;
    cout<<"Введите название точки:";
    cin.ignore(1,'\n');
    getline(cin,poi);
    for(unsigned int i=0;i<vecPoint.size();i++){
        if(poi==vecPoint[i].getName()){
            flag=1;
            n=i;
        }
    }
    if(flag==1){
        vecPoint.erase(vecPoint.begin()+n);
        cout<<"Точка удалена"<<endl;
        numbOfPoint--;
    }
    else
        cout<<"Точка не найдена"<<endl;
}
