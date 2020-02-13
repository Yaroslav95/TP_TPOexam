#include "MyFloat.h"
#include "Test.h"
#include "Exceptions.h"

MyFloat::MyFloat() //к-р по умолчанию
{
	n = 0;
}

MyFloat::MyFloat(float n) //к-р иннициализации
{
	this->n = n;
}

MyFloat::MyFloat(const MyFloat& B) //к-р копии
{
	n = B.n;
}

MyFloat::~MyFloat() //деструктор
{}

MyFloat MyFloat::operator = (const MyFloat &B) //оп присваивания
{
	n = B.n;
	return *this;
}

bool MyFloat::operator != (const MyFloat &B)
{
	return (n != B.n);
}

bool MyFloat::operator != (const float m)//неравенство 
{
	return (n != m);
}

bool MyFloat::operator == (const MyFloat &B)
{
	return (n == B.n);
}

bool MyFloat::operator <= (const MyFloat &B)
{
	return n <= B.n;
}

bool MyFloat::operator >= (const MyFloat &B)
{
	return n >= B.n;
}


bool MyFloat::operator < (const MyFloat &B)
{
	return n < B.n;
}

bool MyFloat::operator > (const MyFloat &B)
{
	return n > B.n;
}

MyFloat MyFloat::operator - () //унарный минус
{
	MyFloat buf(-n);
	return buf;
}

MyFloat MyFloat::operator + () //унарный плюс
{
	return n;
}

MyFloat MyFloat::operator + (const MyFloat B)//бин сложение
{
	MyFloat buf;
	float a = n, b = B.n, C;
	C = a + b;
	if (C < INT_MIN || C > INT_MAX)
	{
		throw new OuttaRange(a, '+', b);
	}
	else
	{
		buf.n = n + B.n;
		return buf;
	}
}

MyFloat MyFloat::operator - (const MyFloat B) //throw (OuttaRange)  //вычитание
{
	MyFloat buf;
	float a = n, b = B.n, C;
	C = a - b;
	if (C < INT_MIN || C > INT_MAX)
	{
		throw new OuttaRange(a, '-', b);
	}
	else
	{
		buf.n = n - B.n;
		return buf;
	}
}

MyFloat MyFloat::operator * (const MyFloat B)// throw (OuttaRange) //бинарное умножение
{
	MyFloat buf;
	float a = n, b = B.n, C;
	C = a * b;
	if (C < INT_MIN || C > INT_MAX)
	{
		throw new OuttaRange(a, '*', b);
	}
	else
	{
		buf.n = n * B.n;
		return buf;
	}
}

MyFloat MyFloat::operator / (const MyFloat B)// throw (DivByZero) //бинарное деление
{
	MyFloat buf;
	if (B.n == 0)
	{
		throw new DivByZero(this->n);
	}
	else
	{
		buf.n = this->n / B.n;
		return buf;
	}
}

MyFloat operator + (const float m, const MyFloat B) //throw (OuttaRange)
{
	MyFloat buf;
	float b = B.n, C;
	C = m + b;
	if (C < INT_MIN || C > INT_MAX)
	{
		throw new OuttaRange(m, '+', b);
	}
	else
	{
		buf.n = m + B.n;
		return buf;
	}
}

MyFloat operator - (const float m, const MyFloat B)// throw (OuttaRange)
{
	MyFloat buf;
	float a = m, b = B.n, C;
	C = a - b;
	if (C < INT_MIN)
	{
		throw new OuttaRange(m, '-', b);
	}
	else
	{
		buf.n = m - B.n;
		return buf;
	}
}

MyFloat operator * (const float m, const MyFloat B)// throw (OuttaRange)
{
	MyFloat buf;
	float a = m, b = B.n, C;
	C = a * b;
	if (C < INT_MIN || C > INT_MAX)
	{
		throw new OuttaRange(m, '*', b);
	}
	else
	{
		buf.n = m * B.n;
		return buf;
	}
}

MyFloat operator / (const float m, const MyFloat B)// throw (DivByZero)
{
	MyFloat buf;
	if (B.n == 0)
	{
		throw new DivByZero(m);
	}
	else
	{
		buf.n = m / B.n;
		return buf;
	}
}

ostream &operator << (std::ostream &os, const MyFloat &number)
{
	os << number.n;
	return os;
}
