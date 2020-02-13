#pragma once
#include <iostream>

class Point
{
public:
    float x1, y1;
	float angle;
//public:
    Point();
    Point(float, float);
	Point(Point& B);
	Point& operator= (const Point& B);
	Point operator+(const Point& B);
	//friend void operator<<(std::ostream& os, const Point &B);

	void move(float, float);

     friend std::ostream& operator<<( std::ostream& os, Point complexNumeric);//перегруженный оператор ostream вызывает ссылку на объект, для котрого был вызван

    ~Point();

    float measure();
};
