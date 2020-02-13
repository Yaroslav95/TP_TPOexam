#include "Vector.h"
#include "Test.h"
#include "Exceptions.h"

void main()
{
	test();
	float x[] = { 3, 5, 2, 6 };
	float y[] = { 1, 1, 1, -1.4 };
	try
	{
		Vector A((sizeof(x) / sizeof(x[0])), x), B((sizeof(y) / sizeof(y[0])), y);
		Vector C(sizeof(x) / sizeof(x[0]));

		C = -A + 2 * A - A + B * 2;
		C[0] = (A, B); //скалярное произведение
		C[6] = 1; //ошибка!!
		cout << "A = " << A << "\n\n";
		cout << "B = " << B << "\n\n";
		cout << "C = " << C << "\n\n";
	}
	catch (Exception* e)
	{
		e->message();
	}
	_getch();
}
