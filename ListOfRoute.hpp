#pragma once

#include <vector>
#include "Route.hpp"
/*!
  @class ListOfRoute
  Класс,предназначенный для хранения списка маршрутов. Содержит -get и -set методы,
  а также методы добавления и удалнения маршрутов
*/
class ListOfRoute {
private:
	  //!Вектор маршрутов
      std::vector<Route> vecRoute;
	  //!Количество маршрутов
      unsigned int numbOfRoute;
public:
	  /*!
		Метод,предназначенный для добавления маршрутов
	  */
      void append();
	  /*!
		Метод,предназначенный для удаления маршрутов
	  */
      void remove();
	   /*!
		Метод,предназначенный для инициализации вектора и количества маршрутов
		\param [in] _vecRoute вектор маршрутов
		\param [in] numb количество маршрутов
	  */
      void setRoute(std::vector<Route> _vecRoute, unsigned int numb);
	   /*!
			Метод,возвращающий вектор маршрутов
			\return vecRoute
	  */
      std::vector<Route> getRoute();
	   /*!
			Метод,возвращающий количество маршрутов
			\return numbOfRoute
	  */
      unsigned int getNumbRoute();
};
