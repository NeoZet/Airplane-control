#include <iostream>
#include <fstream>
#include <iterator>
#include "Route.hpp"
#include "Point.hpp"
#include "Plane.hpp"
#include "ListOfPlane.hpp"
#include "Flight.hpp"

using namespace std;

int main()
{
    ifstream in("listRoute.txt");
    Route r;
    in >> r;
    r.generateVecEdge();
    r.calcDistance();
    cout << r <<endl;



    /* Flight fl;
    vector<Flight> listFl;
    int qty=0;
    while(in >> fl) {
        if(in.eof()) break;
        listFl.push_back(fl);
        qty++;
    }
    for(unsigned int i = 0; i<listFl.size(); i++)
        cout << listFl[i] << endl;
*/


    /*Plane r;

    ListOfPlane p;
    int len=0;
    vector<Plane> _listPlane;
    while(in >> r) {
        if(in.eof()) break;
        _listPlane.push_back(r);
        len++;
    }
    p.setPlane(_listPlane, len);
    for(unsigned int i = 0; i<p.getPlane().size(); i++)
        cout << p.getPlane()[i] << endl;
*/
}
