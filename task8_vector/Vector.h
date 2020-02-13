#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <math.h>

using std::endl;
using std::cout;
using std::ostream;

class Vector
{
public:
	int dim;
	float *dat;
	Vector(); //к-р по умолчанию
	Vector(int d); //к-р иннициализации
	Vector(int d, float *insides); //к-р иннициализации
	Vector(Vector& vect); //к-р копии
	~Vector(); //деструктор

	Vector operator = (Vector& vect); //оп присваивания
	bool operator == (Vector& vect);
	bool operator != (Vector& vect);

	Vector operator - (); //унарный минус
	Vector operator + (const Vector vect); //сумма векторов
	Vector operator - (const Vector vect); //разность векторов
	Vector operator * (const Vector vect); //произведение соотв координат векторов
	Vector operator * (const float n);

	float operator , (const Vector vect); //скалярное умножение
	float& operator [](const int& index);

	friend Vector operator * (float n, Vector vect);
	friend Vector operator / (Vector vect, float m);
	friend ostream& operator << (ostream& outs, Vector& vect);
};
