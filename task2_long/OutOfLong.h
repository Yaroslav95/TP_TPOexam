#pragma once
class OutOfLong {
public:
    long left;
    long right;
    char* op;
    OutOfLong(char* _op, long _left, long _right);
    OutOfLong(char* _op, long _right);
};