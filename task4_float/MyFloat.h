#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class MyFloat
{
public: float n;
		MyFloat(); //к-р по умолчанию
		MyFloat(float n); //к-р иннициализации
		MyFloat(const MyFloat &B); //к-р копии
		~MyFloat(); //деструктор

		MyFloat operator = (const MyFloat &B); //оп присваивания
		bool operator != (const float m); //неравенство
		bool operator != (const MyFloat &B); //неравенство 
		bool operator == (const MyFloat &B); //равенство
		bool operator <= (const MyFloat &B);
		bool operator >= (const MyFloat &B);
		bool operator < (const MyFloat &B);
		bool operator > (const MyFloat &B);

		MyFloat operator - (); //унарный минус
		MyFloat operator + (); //унарный плюс

		MyFloat operator + (const MyFloat B); //бин сложение
		MyFloat operator - (const MyFloat B); //вычитание
		MyFloat operator * (const MyFloat B); //бинарное умножение
		MyFloat operator / (const MyFloat B); //бинарное деление

		friend MyFloat operator + (const float m, const MyFloat B);
		friend MyFloat operator - (const float m, const MyFloat B);
		friend MyFloat operator * (const float m, const MyFloat B);
		friend MyFloat operator / (const float m, const MyFloat B);
		friend ostream& operator << (std::ostream& os, const MyFloat & number);
};
