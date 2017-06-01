#pragma once

#include <string>
#include <utility>
#include "Flight.hpp"
#include "PlanOfFlight.hpp"
/*!
  \file
  @class Dispatcher
  Класс, описывающий диспетчера, и позволяющий вести сравнение реального полета с планом
  и корректировать конечные данные. Содержит конструктор,-get и -set методы,
  перегруженные операторы ввода/вывода. Имеет метод корректировки и отслеживания
  полета, а также методы перерассчета оставшегося расстояния и времени.
*/
class Dispatcher{
private:
    //!Имя диспетчера
    std::string name;
    //!План полета самолета
    PlanOfFlight plan;
    //!Реальный полет самолета
    Flight flight;
public:
    /*!
     * Конструктор, инициализирующий план полета
     * \param _plan план полета самолета
     */
    Dispatcher(PlanOfFlight _plan) : plan(_plan) {}
    /*!
     * Метод, инициализирующий данные полета
     * \param _flight данные полета
     */
    void setFlight(Flight _flight);
    /*!
     * Метод, позволяющий отследивать сравнивать  и корректировать
     * полет самолета в соответсвии с планом полета
     * \param dist длина пути
     * \param averSpeed средняя скорость
     */
    void correctFlight(int *dist, int *averSpeed);
    /*!
     * Метод, позволяющий перерассчитывать время полета,
     * в соответсвии с изменяющимися данными полета
     * \param averSpeed средняя скорость
     * \return time рассчетное время прибытия
     */*/
    std::pair<int, int> recalcFlightTime(int *averSpeed);
    /*!
     * Метод, позволяющий перерассчитывать оставшийся путь,
     * в соответствии с изменяющимися данными о полете
     * \param dist пройденный путь
     */
    void recalcDistance(int *dist);
    /*!
     * Метод, определяющий точки, через которые
     * прооходит полет в данный момент
     * \return point точка, через которую пролетел самолет
     */
    std::string findLocateOnMap();
};
