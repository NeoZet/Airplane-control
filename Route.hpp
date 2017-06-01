#pragma once

#include <string>
#include <vector>
#include <utility>
#include "Point.hpp"
/*!
 * \file
 * @class  Route
    Класс,описывающий маршруты.Содержит -get и -set методы,
    перегруженные операторы ввода/вывод,а также методы,позволяющие рассчитать
    расстояние между любыми двумя точками, сгенерировать вектор ребер и рассчитать длину маршрута.
*/
class Route {
private:
	//!Название маршрута
    std::string name;
	//!Расстояние между начальным и конечным пунктом
    int distance;
	//!Вектор точек
    std::vector<Point> vecInsidePoint;
	//!Вектор рёбер
    std::vector<int> edgeList;

public:
	/*!
		Метод,позволяющий рассчитать длину ребра
		\param [in] start начало ребра
		\param [in] finish конец ребра
	*/
    int calcLengthOfEdge(Point start, Point finish);
	/*!
        Метод,позволяющий рассчитать длину маршрута
	*/
    void calcDistance();
	/*!
        Метод, позволяющий сгенерировать вектор ребер
	*/
    void generateVecEdge();
	/*!
		Метод,предназначенный для инициализации названия маршрута
		\param [in] _name название маршрута
	*/
    void setName(std::string _name);
	/*!
		Метод,предназначенный для инициализации вектора точек
		\param [in] _vecInsidePoint вектор точек
	*/
    void setInsidePoint(std::vector<Point> _vecInsidePoint);
	/*!
		Метод,возвращающий название маршрута
		\return name
	*/
    std::string getName();
	/*!
		Метод,возвращающий вектор точек
		\return vecInsidePoint
	*/
    std::vector<Point> getInsidePoint();
	/*!
		Метод,возвращающий вектор вектор рёбер
		\return edgeList
	*/
    std::vector<int> getEdgeList();
	/*!
		Метод,возвращающий Расстояние между начальным и конечным пунктом
		\return distance
	*/
    int getDistance();

    /*!
     * Перегруженный оператор присваивания
     * \param [in] &route ссылка на присваеваемый объект
     * \return &Route
     */
    Route &operator =(const Route &route);

	/*!
		Перегруженный оператор вывода для класса Route
		\param [out] &out Ссылка на поток вывода
		\param [in] &route	Ссылка на класс Route
	*/
    friend std::ostream& operator<< (std::ostream& out, Route& route);
	/*!
		Перегруженный оператор ввода данных для класса Route
      \param [in] &in Ссылка на поток ввода
      \param [out] &route Ссылка на класс Route
	*/
    friend std::istream& operator>> (std::istream& in, Route& route);
};
