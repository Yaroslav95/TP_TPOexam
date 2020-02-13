#include <iostream>
#include"date.h"


using namespace std;


void unit_test_date_class()
{
	setlocale(0, "");
	int day, m, y;
	date d, q;
	cout << "\nВведите первую дату:\n";
	do
	{

		cout << "Введите пожалуйста день 1-31\n-->";
		cin >> day;
		cout << "Введите пожалуйста месяц 1-12\n-->";
		cin >> m;
		cout << "Введите пожалуйста год 1-65000\n-->";
		cin >> y;
		d.setDay(day); d.setMounth(m); d.setYear(y);
	} while (d.error == false);

	cout << "\nВведите вторую дату:\n";
	do
	{
		cout << "Введите пожалуйста день 1-31\n-->";
		cin >> day;
		cout << "Введите пожалуйста месяц 1-12\n-->";
		cin >> m;
		cout << "Введите пожалуйста год 1-65000\n-->";
		cin >> y;
		q.setDay(day); q.setMounth(m); q.setYear(y);
	} while (q.error == false);

	cout << "\n\nСмотрим разницу в датах\n";

	cout << q.getDay() << "." << q.getMounth() << "." << q.getYear() << " - " << d.getDay() << "." << d.getMounth() << "." << d.getYear() << " = " << q - d << "\n";

}


void main()
{
	setlocale(0, "");

	unit_test_date_class(); 

	system("pause");
}
