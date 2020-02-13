#pragma once
#include "Vector.h"
class Exception
{
public:
	virtual void message() = 0;
};

class DivByZero : public Exception
{
public:
	float numerator;
	Vector vect;
	DivByZero(float _numerator);
	DivByZero(Vector &_vect);
	void message();
};

class OutOfRange : public Exception
{
public:
	int A;
	int B;
	char operation;
	OutOfRange(int _A, char _operation);
	OutOfRange(int _A, char _operation, int _B);
	void message();
};


class DimMismatch : public Exception
{
public:
	int dim1, dim2;
	char caseof;
	DimMismatch(int _dim, int _dim2);
	DimMismatch(int _dim, int _dim2, char _caseof);
	void message();
};
