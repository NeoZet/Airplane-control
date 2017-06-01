#pragma once

#include <string>
#include <utility>
#include <fstream>

/*!
  @class Point
  Класс, описывающий точки. Содержит конструкторы,-get и -set методы,
  перегруженные операторы ввода/вывода.
*/
class Point{
private:
    //!Название точки		
    std::string name;
    //!Координаты точки
    std::pair<float,float> coord;
    //!Спецификация точки 
    std::string specifier;
public:
  	/*!
		Конструктор по умолчанию
	*/
    Point() {}
	/*!
		Конструктор,предназначенный для инициализации объекта
	*/
    Point(std::string _name, std::pair<float,float> _coord)
       : name(_name), coord(_coord) {}
	/*!
		Метод,определяющий спецификацию точки
	*/
   void defineSpecifier();
	/*!
		Метод,предназначенный для инициализации названия точки 
		\param [in] _name 
	*/
   void setName(std::string _name);
	/*!
		Метод,предназначенный для инициализации координат
		\param [in] _coord
	*/
   void setCoord(std::pair<float, float> _coord);
	/*!
		Метод,возвращающий название точки
		\return name
	*/
   std::string getName();
	/*!
		Метод,возвращающий координаты
		\return coord
	*/
   std::pair<float,float> getCoord();
	/*!
		Метод,возвращающий спецификацию 
		\return specifier
	*/
   std::string getSpecifier();

   /*!
		\param [out] &out Ссылка на поток вывода
     	\param [in] &point Ссылка на класс Point
	*/
   friend std::ostream& operator<< (std::ostream& out, Point& point);
	/*!
		\param [in] &in Ссылка на поток ввода
      	\param [out] &point Ссылка на класс Point
	*/
   friend std::istream& operator>> (std::istream& in, Point& point);
};
