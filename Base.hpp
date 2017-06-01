#pragma once

#include "ListOfPlane.hpp"
#include "ListOfPoint.hpp"
#include "ListOfRoute.hpp"
#include "PlanOfFlight.hpp"
#include "Route.hpp"
#include "Plane.hpp"
#include <vector>

/*!
  \file
  @class Base
  Основной рабочий класс, содержащий методы загрузки/сохранения данных,
  создания плана полета и метод, содержащий меню программы и запускающий её
*/

class Base{
public:
    /*!
     * Метод, загружающий данные из файлов в векторы соответвующих данных
     * \param pl вектор самолетов
     * \param rt вектор маршрутов
     * \param point вектор точек
     */
    void LoadData(ListOfPlane &pl,ListOfRoute &rt,ListOfPoint &point);
    /*!
     * Метод, сохраняющий данные из контейнеров в соответсвующие файлы
     * \param pl вектор самолетов
     * \param rt вектор маршрутов
     * \param point вектор точек
     */
    void SaveData(ListOfPlane &pl,ListOfRoute &rt,ListOfPoint &point);
    /*!
     * Метод, позволяющий создавать новый план полета
     * \param vecRt вектор маршрутов
     * \param vecPlane вектор самолетов
     * \return plan план полета
     */
    PlanOfFlight makePlanOfFlight(std::vector <Route> vecRt,std::vector <Plane> vecPlane);
    /*!
     * Метод, содержащий меню программы и запускающий её работу
     */
    int run();
};
