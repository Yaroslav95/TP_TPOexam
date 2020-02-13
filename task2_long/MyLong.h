#include <iostream>
using namespace std;
class MyLong {
public:
    long n;
    MyLong();
    MyLong(long n);
    MyLong(char *str);
    MyLong(const MyLong &B);
    MyLong& operator=(const MyLong &B);
    bool operator!=(const MyLong &B);
    ~MyLong();
    MyLong operator-();
    MyLong operator+(MyLong &B);
    friend MyLong operator+(long m, MyLong B);
};