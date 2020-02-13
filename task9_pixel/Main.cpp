#include <iostream>
#include "windows.h"
#include "Point.h"
using namespace std;

/*
9.	Объявите класс для работы с пикселем на экране. Определите конструкторы по умолчанию, копии, 
инициализации, операцию присваивания. Перегрузите бинарную операцию векторного сложения пикселей. 
Определите методы, необходимые для перемещения пикселя по прямой линии в заданном направлении. 
Напишите тестирующую функцию и Windows-приложение с использованием класса. 
*/

int main() {
 
    Point p1(5, 3);
	Point p2(2, 2);
	Point result_p3(0, 0);
	result_p3 = p1 + p2;
     // Test
    cout << result_p3 << endl;
	 cout << "------------------------------------------" << endl;

	//for (int dx = 0; dx < sqrt(pow((result_p3.x1), 2) + pow((result_p3.y1), 2)); dx++)
	
    for (float dx = 0; dx <= abs(result_p3.x1); dx++){
		result_p3.move(dx, 0);
	  }
	       
    system("pause");
    return 0;

}
