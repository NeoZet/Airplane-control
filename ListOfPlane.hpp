#pragma once

#include <vector>
#include "ListOfPlane.hpp"
#include "Plane.hpp"
/*!
  @class ListOfPlane
  Класс,преназначенный для хранения списка самолётов. Содержит -get и -set методы,
  а также методы добавления и удаления самолётов.
*/
class ListOfPlane{
private:
	//!Вектор самолётов
    std::vector<Plane> vecPlane;
	//!Количество самолётов
    unsigned int numbOfPlane;
public:
	/*!
		Метод,предназначенный для добавления самолётов
	*/	
    void append();
	/*!
		Метод,предназначенный для удаления самолётов
	*/
    void remove();
	/*!
		Метод,предназначенный для инициализации вектора и количества самолётов
		\param [in] _vecPlane вектор самолётов 
		\param [in] numb количество самолётов
	*/
    void setPlane(std::vector<Plane> _vecPlane, unsigned int numb);
	/*!
		Метод,возвращающий вектор самолётов
		\return vecPlane
	*/
    std::vector<Plane> getPlane();
	/*!
		Метод,возвращающий количество самолётов
		\return numbOfPlane
	*/
    unsigned int getNumbPlane();
};
