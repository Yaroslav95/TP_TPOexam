#include "OutOfLong.h"
    
OutOfLong::OutOfLong(char* _op, long _left, long _right) {
        left = _left;
        right = _right;
        op = _op;
}

OutOfLong::OutOfLong(char* _op, long _right) {
        right = _right;
        op = _op;
}

