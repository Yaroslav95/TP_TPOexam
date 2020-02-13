#include "date.h"
#include <iostream>
using namespace std;
date::date()
{
    struct tm *timeinfo;
    time_t tt = time(NULL);
    timeinfo = localtime(&tt);
    this->day = timeinfo->tm_mday;
    this->month = timeinfo->tm_mon + 1;
    this->year = timeinfo->tm_year + 1900;
}

date::date(int year, int mon, int day)
{
    try
    {
        if (mon > 0 && day > 0 && year > 0)
        {
            if (maxDays(mon, year) >= day)
                this->day = day;
            else throw "\nОшибка формата даты! Неверный введен день!\n";

            if (mon <= 12)
                this->month = mon;
            else throw "\nОшибка формата даты! Неверно введен месяц!\n";

            this->year = year;
            this->error = true;
        }
        else { throw "\nОшибка формата даты! Введенные данные неверны! Пожалуйста повторите ввод!\n"; };
    }
    catch (char* str)
    {
        cout << str << endl;
        this->error = false;
    }
}

date::~date()
{
}


date::date(const date& dat)
{
    this->day = dat.day;
    this->month = dat.month;
    this->year = dat.year;
}

date& date::operator= (const date& dat)
{
    if (this == &dat)
        return *this;
    this->month = dat.month;
    this->year = dat.year;
    return *this;
}


date::operator char *() const
{
    char *q = new char[10];
    sprintf(q, "%d.%d.%d", this->day, this->month, this->year);
    return q;
}

// Бинарный -, возвращает разницу в днях
int operator- (date& dat1, date& dat2)
{
    int result = dat1.day + maxDays(dat2.month, dat2.year) - dat2.day;
    int mounth = dat2.month + 1;
    int year = dat2.year + 1;

    while (mounth <= 12) {
        result += maxDays(mounth, dat2.year);
        mounth++;
    }
    mounth = dat1.month - 1;
    while (mounth > 0) {
        result += maxDays(mounth, dat1.year);
        mounth--;
    }
    while (year < dat1.year) {
        result += dayOfYear(year);
        year++;
    }
    if (dat1.year==dat2.year) { return result - dayOfYear(dat1.year); }
    
    return result;
}


int dayOfYear(int year) {

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 366;
    }
    else {
        return 365;
    }
}

int maxDays(int mon, int year)
{
    int mas[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (mon != 2 && mon <= 12) {
        return mas[mon];
    }
    else {
        return 28 + dayOfYear(year) % 365;
    }

}

int date::getDay()
{
    return int(this->day);
}

int date::getMounth()
{
    return int(this->month);
}

int date::getYear()
{
    return int(this->year);
}


bool date::setDay(int day)
{
    try
    {
        if (day > 0 && day <= maxDays(this->month, this->year))
            this->day = day;
        else throw "\nДень введен неверно! Пожалуйста повторите операцию!\n";
        return true;
    }
    catch (char* str)
    {
        cout << str << endl;
        return false;
    }

}


bool date::setMounth(int mon)
{
    try
    {
        if (mon > 0 && mon <= 12)
            this->month = mon;
        else throw "\nМесяц введен неверно! Пожалуйста повторите операцию!\n";
        return true;
    }
    catch (char* str)
    {
        cout << str << endl;
        return false;
    }
}


bool date::setYear(int year)
{
    try
    {
        if (year > 0)
            this->year = year;
        else throw "\nГод введен неверно, не может быть < 0! Пожалуйста повторите операцию!\n";
        return true;
    }
    catch (char* str)
    {
        cout << str << endl;
        return false;
    }
}
