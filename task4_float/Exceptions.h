#pragma once

class Exception
{
public:
	virtual void msg() = 0;
};

class DivByZero : public Exception
{
public:
	int numerator;
	DivByZero(int _numerator);
	void msg();
};

class OuttaRange : public Exception
{
public:
	int A;
	int B;
	char operation;
	OuttaRange(int _A, char _operation, int _B);
	void msg();
};
