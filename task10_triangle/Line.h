#pragma once
#include "Point.h"
class Line: public Point
{
protected:
    int x2, y2;
public:
    Line();
    Line(int, int, int, int);
    float measure();
    ~Line();
};
