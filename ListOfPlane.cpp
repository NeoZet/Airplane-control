#include <iostream>
#include <vector>
#include "ListOfPlane.hpp"
#include "Plane.hpp"
#include <string>

using namespace std;

void ListOfPlane::setPlane(vector<Plane> _vecPlane,unsigned int numb){
    vecPlane=_vecPlane;
    numbOfPlane=numb;
}
vector<Plane> ListOfPlane::getPlane(){
    return vecPlane;
}
unsigned int ListOfPlane::getNumbPlane(){
    return numbOfPlane;
}
void ListOfPlane::appened(){
    string name_plane;
    int topSpeed,topAltitude,topDistance;
    cout<<"Введите название самолёта:";
    cin.ignore(1,'\n');
    getline(cin,name_plane);
    cout<<endl<<"Введите максимальную скорость:";
    cin>>topSpeed;
    cout<<endl<<"Введите максимальную высоту полёта:";
    cin>>topAltitude;
    cout<<endl<<"Введите максимальную дальность полёта:";
    cin>>topDistance;
    Plane plane(name_plane,topSpeed,topAltitude,topDistance);
    vecPlane.push_back(plane);
}
void ListOfPlane::remove(){
    cout<<"Введите название самолёта:";
    string name_plane;
    cin.ignore(1,'\n');
    getline(cin,name_plane);
    int flag,n;
    for(unsigned int i=0;i<vecPlane.size();i++){
        if(name_plane==vecPlane[i].getName()){
            n=i;
            flag=1;
        }
    }
    if(flag==1){
        vecPlane.erase(vecPlane.begin()+n);
        cout<<endl<<"Самолёт удалён"<<endl;
    }
    else
        cout<<"Самолёт не найден"<<endl;
}
