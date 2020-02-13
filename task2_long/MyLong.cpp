#include "MyLong.h"
#include "OutOfLong.h"

MyLong::MyLong() {
    n = 0;
}
MyLong::MyLong(long n) {
    this->n = n;
}
MyLong::MyLong(char *str) {
    std::cout << str << n;
}

MyLong::MyLong(const MyLong &B) {
    n = B.n;
}

MyLong& MyLong::operator=(const MyLong &B) {
    n = B.n;
    return *this;

}
MyLong::~MyLong() {}

MyLong MyLong::operator-() {
    
    MyLong buf;
    long long c;
    c = -n;
    if ((c < LONG_MIN) || (c > LONG_MAX)) {
        throw new OutOfLong("-A", n);
    }
    buf.n = (long)c;
    return buf;
}

MyLong MyLong::operator+(MyLong &B) {
    MyLong buf;
    long long c;
    c = n + B.n;
    if ((c < LONG_MIN) || (c > LONG_MAX)) {
        throw new OutOfLong("+", n, B.n);
    }
    buf.n = c;
    return buf;
}

bool MyLong::operator!=(const MyLong &B) {
    return (this->n) != B.n;
}

