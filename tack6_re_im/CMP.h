#pragma once
#include <iostream>
using namespace std;
class CMP
{
public:
	float re, im; //действитеьная и мнимая части числа
public:
	CMP();//конструктор по умолчанию
	CMP(float re);
	CMP(float re, float im);//конструктор инициализации
	CMP(CMP& C);
	bool operator!();//логическое отрицание
	operator float() const;//явное приведение типов
	CMP operator+(CMP  C);
	CMP operator*(CMP  C);
	CMP operator/(CMP  C);
	CMP &operator=(CMP& C);
	friend ostream& operator<<( std::ostream& os, CMP complexNumeric);//перегруженный оператор ostream вызывает ссылку на объект, для котрого был вызван
	~CMP(void);
};

