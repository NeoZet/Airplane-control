#pragma once

#include <string>
#include <fstream>

/*!
 * \file
 * @class  Plane
    Класс,описывающий самолёты.Содержит конструкторы,-get и -set методы,
  перегруженные операторы ввода/вывода, присваивания.
*/
class Plane{
private:
	//!Название самолёта
    std::string name;
	//!Максимальная скорость самолёта
    int topSpeed;
	//!Максимальная высота полёта
    int topAltitude;
	//!Максимальная дальность полёта
    int topDistance;
public:
	/*!
		Конструктор по умолчанию	
	*/
    Plane();
	/*!
        Конструктор,инициализирующий атрибуты класса
	*/
    Plane(std::string _name,int _topSpeed,int _topAltitude,int _topDistance)
        : name(_name), topSpeed(_topSpeed), topAltitude(_topAltitude), topDistance(_topDistance) {}
	 /*!
      Метод,предназначенный для инициализации названия самолёта
      \param [in] _name название самолёта
    */
    void setName(std::string _name);
	/*!
		Метод,возвращающий название самолёта
		\return name Название самолёта
	*/
    std::string getName();
	/*!
		Метод,возвращающий масимальную высоту полёта
		\return topAltitude Максимальная высота полёта
	*/
    int getTopAltitude();
	/*!
		Метод,возвращающий масимальную скорость самолёта
		\return topSpeed Максимальная скорость 
	*/
    int getTopSpeed();
	/*!
		Метод,возвращающий максимальную дальность полёта
		\return topDistance Максимльная дистанция полёта
	*/
    int getTopDistance();
	
	/*!
		Перегруженный оператор присваивания для класса Plane
		\param [in] &plane Ссылка на класс Plane
			
	*/
    Plane operator = (const Plane &plane);
	/*!
        Перегруженный оператор вывода данных для класса Plane
		\param [out] &out Ссылка на поток вывода
		\param [in] &plane	Ссылка на класс Plane
	*/
    friend std::ostream& operator<< (std::ostream& out, Plane& plane);
	/*!
      Перегруженный оператор ввода данных для класса Plane
      \param [in] &in Ссылка на поток ввода
      \param [out] &plane Ссылка на класс Plane
     */
    friend std::istream& operator>> (std::istream& in, Plane& plane);
};
