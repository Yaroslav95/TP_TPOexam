#include"Exceptions.h"


DimMismatch::DimMismatch(int _dim1, int _dim2)
{
	dim1 = _dim1;
	dim2 = _dim2;
}

DimMismatch::DimMismatch(int _dim1, int _dim2, char _caseof)
{
	dim1 = _dim1;
	dim2 = _dim2;
	caseof = _caseof;
}

void DimMismatch::message()
{
	FILE *ExcLog;
	fopen_s(&ExcLog, "Exception log.txt", "a");
	if (caseof == '1')
	{
		fprintf_s(ExcLog, "Trying to work with %d element when vector's dimension is %d", dim2, dim1);
		fprintf_s(ExcLog, "\nDimMismatch Exception!\n\n", dim2);
	}
	else
	{
		fprintf_s(ExcLog, "First vector's dimension is %d\n", dim1);
		fprintf_s(ExcLog, "Second vector's dimension is %d\nDimMismatch Exception!\n\n", dim2);
	}
	fclose(ExcLog);
	exit(1);
}


DivByZero::DivByZero(float _numerator)
{
	numerator = _numerator;
}
DivByZero::DivByZero(Vector &_vect)
{
	vect = _vect;
	numerator = vect[0];
}
void DivByZero::message()
{
	FILE *ExcLog;
	fopen_s(&ExcLog, "Exception log.txt", "a");
	fprintf_s(ExcLog, "Attempt to divide %f by zero. DivByZero exception!\n\n", numerator);
	fclose(ExcLog);
	exit(1);
}


OutOfRange::OutOfRange(int _A, char _operation)
{
	A = _A;
	operation = _operation;
}
OutOfRange::OutOfRange(int _A, char _operation, int _B)
{
	A = _A;
	operation = _operation;
	B = _B;
}
void OutOfRange::message()
{
	FILE *ExcLog;
	fopen_s(&ExcLog, "Exception log.txt", "a");
	if (operation != '0')
	{
		fprintf_s(ExcLog, "%d %c %d caused OutOfRange exception!\n\n", A, operation, B);
	}
	else
	{
		fprintf_s(ExcLog, "%d caused OutOfRange exception!\n\n", A);
	}
	fclose(ExcLog);
	exit(1);
}
