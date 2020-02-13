#include "CMP.h"

CMP::~CMP(void)
{
}

std::ostream& operator<<( std::ostream& os, CMP complexNumeric)
{
	os<<complexNumeric.re<<showpos<<complexNumeric.im<<"j";
	return os; 
}

CMP::CMP()
{
	re = 0;
	im = 0;
}

CMP::CMP(float re)
{
	this->re = re;
	this->im = 0;
}

CMP::CMP(float re, float im)
{
	this->re = re;
	this->im = im;
}

CMP::CMP(CMP & C)
{
	this->im = C.im;
	this->re = C.re;
}

bool CMP::operator!()
{
	if (this->re == 0 && this->im == 0);
	return true;
}

CMP::operator float() const
{
	return re;
}

CMP CMP::operator+(CMP C)
{
	
	re += C.re;
	im += C.im;
	return *this;
}
//Если вы как и я не помните как умножаются эти "чиселки"
//(a + bi)·(a′ + b′i) = (a·a′−b·b′)+(a·b′ + b·a′)i
CMP CMP::operator*(CMP C)
{
	
	re = re*C.re - im*C.im;
	im = re*C.im + C.re*im;
	return *this;
}
//a+b·i
//a′+b′·i
//=
//a·a′+b·b′
//a′2+b′2
//+
//a′·b−b′·a
//a′2+b′2
// · i
CMP CMP::operator/(CMP  C)
{
	CMP buff;
	if (!C) throw "Division by zero";
	buff.re = (re*C.re + im*C.im)/(C.re*C.re + C.im*C.im);
	buff.im =(C.re*im - re*C.im)/(C.re*C.re + C.im*C.im);
	return buff;
}

CMP CMP::operator()()
{

	return CMP();
}

CMP & CMP::operator=(CMP & C)
{
	this->im = C.im;
	this->re = C.re;
	return *this;
}
