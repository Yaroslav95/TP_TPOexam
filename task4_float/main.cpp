#include "MyFloat.h"
#include "Test.h"
#include "Exceptions.h"

void main()
{
	test();
	MyFloat A(2), B(3), C;
	try
	{
		C = 2 * A - B * 3 + A / 2 + 4; //ans = 0*/
	}
	catch (Exception* e)
	{
		e->msg();
	}
	cout << "C = " << C;
	_getch();
}
