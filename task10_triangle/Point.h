#pragma once
#include "Base.h"
class Point: public Base
{
protected:
    int x1, y1;
public:
    Point();
    Point(int, int);
    ~Point();
    float measure();
};

