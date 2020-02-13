#include "FIO.h"

void main()
{
	FIO obj("Fedor"), obj2;
	cout << obj;
	cin >> obj;
	cout << endl << obj.fio.at(2);
	cin.get();
	cin.get();
}
