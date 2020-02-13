#include "Point.h"
#include <math.h> /* atan */ 

Point::Point() {
    x1 = 0;
    y1 = 0;
	angle = 0;
}

Point::Point(float x, float y)
{
    x1 = x;
    y1 = y;
}

Point::Point(Point& B)
{
	this->x1 = B.x1;
	this->y1 = B.y1;
}

Point& Point::operator= (const Point& B){
	this->x1 = B.x1;
	this->y1 = B.y1;
	return *this;
}

Point Point::operator+(const Point& B)
{
	x1 += B.x1;
	y1 += B.y1;
	return *this;
}

/*void operator<<(std::ostream& os, const Point &B)
		{
			os << B.x1 << B.y1 << std::endl;
		}
*/

std::ostream& operator<<( std::ostream& os, Point complexNumeric)
{
	os<<complexNumeric.x1<<" "<<complexNumeric.y1;
	return os; 
}

Point::~Point()
{}


void Point::move(float dx, float dy)
{
	angle = atan(y1/x1);
	dy = dx* tan (angle);
    //this->x1 += dx;
   // this->y1 += x1* tan (angle);
	
	std::cout << dx << " " << dy << std::endl;

	  
}


void Point::move(float Sx, float Sy) // Направление
{
    int dx = 1; // Дельта смещения
    angle = atan((Sy - y1) / (Sx - x1));
    x1 += dx;
    y1 += dx * tan(angle);

}

