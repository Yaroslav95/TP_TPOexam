#include "Test.h"
#include "Exceptions.h"

void test()
{
	float x[] = { 2, 2, 2, 2.5 };
	float y[] = { 1, 1, -1, 1.5 };
	float z[] = { 1 };
	float c[4];
	float res = 0;

	try
	{
		Vector A(4, x), B(4, y), C(4), D(1, z);

		// first test
		for (int i = 0; i < 4; i++)
		{
			c[i] = -x[i] + 2 * y[i] / 2 - y[i];
		}
		Vector result1(sizeof(c) / sizeof(c[0]), c);

		C = -A + 2 * B / 2- B;
		if (C != result1)
		{
			cout << "Test 1: Failed" << endl;
		}

		//second test
		for (int i = 0; i < 4; i++)
		{
			c[i] = 2 * x[i] * y[i] * 3 / 4;
		}
		Vector result2(sizeof(c) / sizeof(c[0]), c);
		C = 2 * A * B * 3 / 4;
		if (C != result2)
		{
			cout << "Test 2: Failed" << endl;
		}

		//third test
		for (int i = 0; i < 4; i++)
		{
			res += x[i] * y[i];
		}
		C[0] = (A, B);

		if (C.dat[0] != res)
		{
			cout << "Test 3: Failed" << endl;
		}
	}
	catch (Exception *e)
	{
		e->message();
	}
}
