#include <iostream>
#include "windows.h"
#include "Base.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#define MAX_COUNT 3
/*
Постройте иерархию классов: точка, отрезок, треугольник с виртуальной функцией mesure, 
вычисл¤ющей меру объекта. Мера точки равна нулю, мера отрезка = длине отрезка,
мера треугольника = площади треугольника. 
В функции main определите одномерный массив из объектов различного типа и найдите суммарную меру элементов массива. 
Напишите тестирующую функцию дл¤ классов Windows-приложение с использованием класса.
*/

int main() {

    Base *obj[MAX_COUNT];
    obj[0] = new Triangle(0, 0, 0, 3, 4, 0);
    obj[1] = new Line(0, 0, 0, 5);
    obj[2] = new Point(7, 12);

    { // Test
        float sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += obj[i]->measure();
        }
        std::cout << sum << std::endl;
        if (abs(sum - 11) > 0.001) {
            std::cout << "Wrong" << std::endl;

        }
    }
    
    system("pause");
    for (int i = 0; i < 3; i++) {
        delete obj[i];
    }
    return 0;

}
