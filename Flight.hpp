#pragma once

#include <utility>
#include <fstream>

/*!
  \file
  @class Flight
  Класс описывающий полет самолета. Имеет -set, -get методы, а также
  перегруженные операторы ввода/вывода, присваивания.
*/

class Flight {
private:
    /*!
     * Реальная скорость самолета
     * в данный момент
     */
    int speed;
    /*!
     * Реальная высота самолета
     * в данный момент
     */
    int altitude;
    /*!
     * Текущее положение самолета
     * по координатам (широта/долгота)
     */
    std::pair<float, float> coord;
    /*!
     * Текущее время
     */
    std::pair<int, int> time;
    /*!
     * Способ передачи данных
     */
    char typeOfCommunicate;

public:
    /*!
     * Метод, предназначенный для инициализации скорости
     * \param [in] _speed
     */
    void setSpeed(int _speed);
    /*!
     * Метод, предназначенный для инициализации высоты
     * \param [in] _altitude
     */
    void setAltitude(int _altitude);
    /*!
     * Метод, предназначенный для инициализации координат
     * \param _coord
     */
    void setCoord(std::pair<float, float> _coord);
    /*!
     * Метод, предназначенный для инициализации времени
     * \param [in] _time
     */
    void setTime(std::pair<int, int> _time);
    /*!
     * Метод, возвращающий скорость
     * \return speed
     */
    int getSpeed();
    /*!
     * Метод, возвращающий высоту полета
     * \return altitude
     */
    int getAltitude();
    /*!
     * Метод, возвращающий текущие координаты самолета
     * \return coord
     */
    std::pair<float, float> getCoord();
    /*!
     * Метод, возвращающий текущее время
     * \return time
     */
    std::pair<int, int> getTime();

    /*!
     * Перегруженный оператор присваивания
     * \param flight ссылка на присваеваемы объект
     */
    Flight operator = (const Flight &flight);
    /*!
     * Перегруженный оператор вывода
     * \param [out] &out Ссылка на поток вывода
     * \param [in] &flight Ссылка на класс Flight
     */
    friend std::ostream& operator<< (std::ostream& out, Flight& flight);
    /*!
     * Перегруженный оператор ввода
     * \param [out] &in Ссылка на поток ввода
     * \param [in] &flight Ссылка на класс Flight
     */
    friend std::istream& operator>> (std::istream& in, Flight& flight);

};