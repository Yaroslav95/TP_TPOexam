#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <time.h>

class date
{

private:
    unsigned int day, month;
    unsigned int year;


public:
    bool error;


    date();
    date(int, int, int);
    ~date();
    date(const date&);
    date& operator =(const date&);
    friend int operator-(date&, date&);
    operator char*() const;

    int getDay();
    int getMounth();
    int getYear();
    bool setDay(int);
    bool setMounth(int);
    bool setYear(int);

};

int maxDays(int, int);// месяц год
int dayOfYear(int);
