#define _CRT_SECURE_NO_WARNINGS
/*
Объявите класс, являющийся надстройкой над asciiz-строкой, то есть над типом char*.
Определите конструкторы по умолчанию, копии, инициализации, операцию явного преобразования типа,
операцию присваивания. Переопределите бинарную операцию сложения (конкатенации) строк.
Переопределите также бинарную операцию индексации строки для обращения к элементу строки на чтение
и запись. Предотвратите выход индекса за диапазон строки.
Напишите тестирующую функцию и Windows-приложение с использованием класса.
*/
#pragma once
#include <iostream>
#include <conio.h>

using std::endl;
using std::cout;
using std::ostream;

class MyCharStar
{
private:
	char* star;
public:
	MyCharStar(); //конструктор по умолчанию +
	MyCharStar(int n); //инициализации +
	MyCharStar(char* str); //инициализации +
	MyCharStar(int n, char* str); //инициализации +
	MyCharStar(const MyCharStar& Star); //копии +
	~MyCharStar(); //деструктор +

	MyCharStar& operator = (char* str); // +
	MyCharStar& operator = (const MyCharStar& Star); // +

	MyCharStar operator + (char* str);
	MyCharStar operator + (const MyCharStar& Star);

	char& operator [] (const int& index);

	friend ostream& operator << (ostream& outs, MyCharStar& Star);
};
