#include "MyFloat.h"
#include "Exceptions.h"

void test()
{
	try
	{
		float a = 5, b = 3, c;
		MyFloat MyA(5), MyB(3), MyC;
		cout << "a = " << a << ", b = " << b << "\n\n";
		cout << "MyA = " << MyA << ", MyB = " << MyB << "\n\n";

		c = 2 + a + b + 2;
		MyC = 2 + MyA + MyB + 2;
		cout << "c = " << c << ", MyC = " << MyC << "\n\n";
		if (MyC != c)
			printf("problem with + \n\n");

		c = 3 - a - b - 2;
		MyC = 3 - MyA - MyB - 2;
		cout << "c = " << c << ", MyC = " << MyC << "\n\n";
		if (MyC != c)
			printf("problem with - \n\n");

		c = 5 / 2 * a * b / 3 * 2;
		MyC = 5 / 2 * MyA * MyB / 3 * 2;
		cout << "c = " << c << ", MyC = " << MyC << "\n\n";
		if (MyC != c)
			printf("problem with * or / \n\n");

		c = (b - 1) / (1 + 1);
		MyC = (MyB - 1) / (1 + 1);
		cout << "c = " << c << ", MyC = " << MyC << "\n\n";
		if (MyC != c)
			printf("problem with * or / \n\n");
	}
	catch (Exception* e)
	{
		e->msg();
	}
}