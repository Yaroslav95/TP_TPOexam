#include "Line.h"
#include "math.h"

Line::Line():Point(){
    this->x2 = 0;
    this->y2 = 0;
}

Line::Line(int x1, int y1, int x2, int y2):Point(x1, y1) {
    this->x2 = x2;
    this->y2 = y2;
}

float Line::measure() {

    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
Line::~Line()
{
}
