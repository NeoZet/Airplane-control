#pragma once

#include <string>
#include <utility>
#include "Route.hpp"
#include "Plane.hpp"

/*!
  \file
  @class PlanOfFlight
  Класс, описывающий план полета самолета. Содержит -get и -set методы,
  а также методы подсчета времени прибытия и времени полета,
  перегруженные операторы ввода/вывода, присваивания
*/


class PlanOfFlight {
private:
    //!Название плана
    std::string name;
    //!Маршрут, выбранный для полета
    Route route;
    //!Самолет, выбранный для полета
    Plane plane;
    //!Рекомендуемая скорость полета
    int recommendSpeed;
    //!Рекомендуемая высота полета
    int recommendAltitude;
    //!Время отправления
    std::pair<int, int> departTime;
    //!Время прибытия
    std::pair<int, int> arriveTime;
    //!Время в пути
    std::pair<int, int> flightTime;
    //!Способ передачи данных (А-automatic, M-manual)
    char typeOfCommunicate;

public:
    /*!
     * Конструктор по умолчанию
     */
    PlanOfFlight() {}
    /*!
      Конструктор, инициализирующий атрибуты класса
     */
    PlanOfFlight(std::string _name, Route _route, Plane _plane, std::pair<int, int> depTime, char typeCom)
        : name(_name), route(_route), plane(_plane), departTime(depTime), typeOfCommunicate(typeCom) {}
    /*!
     * Метод, предназначенный для расчета
     * времени прибытия
     */
    void calcArriveTime();
    /*!
     * Метод, предназначенный для рассчета
     * длительности полета
     */
    void calcFlightTime();
    /*!
     * Метод, загружающий данные маршрута по его названию
     * \param vecRt вектор маршрутов, из которого выполняется загрузка
     */
    void loadRoute(std::vector<Route> vecRt);
    /*!
     * Метод, загружающий данные самолета по его названию
     * \param vecPln вектор самолетов, из которого выполняется загрузка
     */
    void loadPlane(std::vector<Plane> vecPln);
    /*!
     *Метод, возвращающий название плана
     * \return name название плана
     */
    std::string getName();
    /*!
     * Метод, возвращающий маршрут
     * \return route
     */
    Route getRoute();
    /*!
     * Метод, возвращающий самолет
     * \return plane
     */
    Plane getPlane();
    /*!
     * Метод, возвращающий рекомендуемую скорость
     * \return recommendSpeed
     */
    int getRecSpeed();
    /*!
     * Метод, возвращающий рекомендуемую высоту
     * \return recommendAltitude
     */
    int getRecAlt();
    /*!
     * Метод, возвращающий время вылета
     * \return departTime
     */
    std::pair<int, int> getDepartTime();
    /*!
     * Метод, возвращающий время прибытия
     * \return arriveTime
     */
    std::pair<int, int> getArrivTime();
    /*!
     * Метод, возвращающий время полета
     * \return flightTime
     */
    std::pair<int, int> getFlightTime();
    /*!
     * Метод, возвращающий способ передачи данных
     * \return typeOfCommunicate
     */
    char getTypeCommunicate();
    /*!
     * Метод, инициализирующий способ передачи данных
     * A - automatic, M - manual
     * \param type способ передачи данных с самолета диспетчеру
     */
    char setTypeCommunicate(char type);

    /*!
     * Перегруженный оператор присваивания
     * \param &plan ссылка на присваеваемый объект
     */
    PlanOfFlight operator = (const PlanOfFlight &plan);

    /*!
        Перегруженный оператор вывода
        \param [out] &out Ссылка на поток вывода
        \param [in] &plan	Ссылка на класс PlanOfFlight
    */
    friend std::ostream& operator<< (std::ostream& out, PlanOfFlight& plan);
    /*!
        Перегруженный оператор ввода данных
        \param [out] &in Ссылка на поток ввода
        \param [in] &plan Ссылка на класс PlanOfFlight
    */
    friend std::istream& operator>> (std::istream& in, PlanOfFlight& plan);
};
