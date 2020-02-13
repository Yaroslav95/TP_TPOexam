#include "Triangle.h"
#include "math.h"


Triangle::Triangle():Line()
{
    x3 = 0;
    y3 = 0;
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3):Line(x1, y1, x2, y2)
{
    this->x3 = x3;
    this->y3 = y3;
}


float Triangle::measure() {
   
    return 0.5 * abs((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3));

}

Triangle::~Triangle()
{
}
