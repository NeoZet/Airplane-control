#pragma once

#include <string>
#include <utility>

class Point{
private:
    std::string name;
    std::pair<float,float> coord;
    std::string specifier;
public:
   Point(std::string _name, std::pair<float,float> _coord)
       : name(_name), coord(_coord) {}
   //А нужен ли конструктор копирования?
   Point(const Point& point);
   void defineSpecifier();
   void setName(std::string _name);
   void setCoord(std::pair<float, float> _coord);
  // void setSpec(std::string _specifier);
   std::string getName();
   std::pair<float,float> getCoord();
   std::string getSpecifier();

   friend std::ostream& operator<< (std::ostream& out, Point& point);
   friend std::istream& operator>> (std::istream& in, Point& point);
};
