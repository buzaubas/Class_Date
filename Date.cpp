#include <iostream>
#include <numeric>  
#include "Date.h"

Date::Date()
{
    this->time = 0;
}

Date::Date(long long time)
{
    this->time = time;
}

Date::Date(size_t d, size_t m, size_t y)
{
    //starting from 1900 year
    /*int array_1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int d_1, d_2 = 1, m_1, m_2 = 1, y_1, y_2 = 1900, i_r = 0, i_n = std::accumulate(array_1, (array_1 + 12), 0, std::plus<int>());

    d_1 = d;
    m_1 = m;
    y_1 = y;

    for (; y_2 > (y_1 + 1); --y_2)
        i_r += i_n;

    for (int i_1 = (m_1 + 1); i_1 <= 12; ++i_1)
        i_r += array_1[(i_1 - 1)];

    for (int i_1 = (m_2 - 1); i_1 > 0; --i_1)
        i_r += array_1[(i_1 - 1)];
        
    i_r += ((array_1[m_1] - d_1) + d_2);

    this->time = i_r;*/

    this->time = d * 86400 + m * 2592000 + y * 31104000;
}

void Date::currentTime()
{
    std::cout << __DATE__ << " " << __TIME__ << std::endl;
}

void Date::show()
{
    /*size_t d, m, y;
    size_t past_y = 0;
    for (auto i = 1; i <= 4; i++)
    {
        if (i % 4 != 0)
        {
            if (this->time - 31536000 <= 0)
                break;
            this->time -= 31536000;
            past_y++;
        }
        else
        {
            if (this->time - 31622400 <= 0)
                break;
            this->time -= 31622400;
            past_y++;
        }
        std::cout << past_y << std::endl;
    }*/
    size_t d, m, y;
    y = this->time / 31104000;
    m = (this->time - (y * 31104000))/ 2592000;
    d = (this->time - (m* 2592000 + y* 31104000))/ 86400;
    std::cout << d << "." << m << "." << y << std::endl;
}

size_t Date::operator-(const Date& obj)
{
    size_t day;
    day = (this->time - obj.time)/ 86400;
    return day;
}

Date Date::operator+(const size_t obj)
{
    this->time += obj * 86400;
    return *this;
}

Date Date::operator=(const Date& obj)
{
    this->time = obj.time;
    return *this;
}

void Date::operator+=(const size_t obj)
{
    this->time += obj * 86400;
}

bool Date::operator<(const Date& obj)
{
    return this->time < obj.time;
}

bool Date::operator>(const Date& obj)
{
    return this->time > obj.time;
}

bool Date::operator==(const Date& obj)
{
    return this->time == obj.time;
}

bool Date::operator!=(const Date& obj)
{
    return this->time != obj.time;
}
