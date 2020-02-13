#pragma once
#include "Line.h"
class Triangle: public Line
{
protected:
    int x3, y3;
public:
    Triangle();
    Triangle(int, int, int, int, int, int);
    float measure();
    ~Triangle();
};

