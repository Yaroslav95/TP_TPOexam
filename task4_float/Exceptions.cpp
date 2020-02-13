#include "Exceptions.h"
#include "MyFloat.h"

DivByZero::DivByZero(int _numerator)
{
	numerator = _numerator;
}
void DivByZero::msg()
{
	FILE *ExcLog;
	fopen_s(&ExcLog, "Exception log.txt", "a");
	fprintf_s(ExcLog, "Attempt to divide %d by zero. DivByZero exception!\n\n", numerator);
	fclose(ExcLog);
	exit(1);
}

OuttaRange::OuttaRange(int _A, char _operation, int _B)
{
	A = _A;
	operation = _operation;
	B = _B;
}
void OuttaRange::msg()
{
	FILE *ExcLog;
	fopen_s(&ExcLog, "Exception log.txt", "a");
	fprintf_s(ExcLog, "%d %c %d caused OuttaRange exception!", A, operation, B);
	fclose(ExcLog);
	exit(1);
}