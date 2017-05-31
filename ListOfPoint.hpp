#pragma once

#include <vector>
#include "Point.hpp"
/*!
  @class ListOfPoint
  Класс,предназначенный для хранения списка точек Содержит -get и -set методы,
  а также методы добавления и удалнения точек 
*/
class ListOfPoint{
private:
 	//!Вектор точек
    std::vector<Point> vecPoint;
	//!Количество точек
    unsigned int numbOfPoint;
public:

	/*!
		Метод,предназначенный для добалвения точек
	*/
    void appened();
	/*!
		Метод,предназначенный для удаления точек
	*/
    void remove();
	/*!
		Метод,предназначенный для инициализации вектора и количества точек 
		\param [in] _vecP вектор точек
		\param [in] numb количество точек 
	*/
    void setVecPoint(std::vector<Point> _vecP,unsigned int numb);
	/*!
		Метод,возвращающий вектор точек 
		\return vecPoint
	*/
    std::vector<Point> getVecPoint();
	/*!
		Метод,возвращающий количество точек
		\return numbOfPoint
	*/
    unsigned int getNumbPoint();
};
