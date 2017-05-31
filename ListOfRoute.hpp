#pragma once

#include <vector>
#include "Route.hpp"
<<<<<<< HEAD
/*!
  @class ListOfRoute
  Класс,предназначенный для хранения списка маршрутов. Содержит -get и -set методы,
  а также методы добавления и удалнения маршрутов
*/
=======
#include "Point.hpp"

>>>>>>> 5bc9299c59e71dcf57e8f2ca293447372608c7a9
class ListOfRoute {
private:
	  //!Вектор маршрутов
      std::vector<Route> vecRoute;
	  //!Количество маршрутов
      unsigned int numbOfRoute;
public:
<<<<<<< HEAD
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
=======
      void append(std::vector<Point> vecAllPoint);
      void remove();
      std::vector<Point> loadInsPoint(std::vector<Point> vecInsPt, std::vector<Point> vecAllPoint);
>>>>>>> 5bc9299c59e71dcf57e8f2ca293447372608c7a9
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
