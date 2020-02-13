#include <iostream>
#include <string>
#include <vector>
#include "windows.h"
#include "MyLong.h"
using namespace std;

void Test1() {


    MyLong A(2), B(3), res;
    long c;
    {
        long A = 2, B = 3;
        c = A + B;
    }
    res = A + B;

    if (res != c) {

        cout << "wrong";

    }

}


int main() {

    Test1();
    system("pause");

}