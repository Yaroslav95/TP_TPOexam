#ifndef UNSCHAR_H
#define UNSCHAR_H

class unsChar
{
public:
    unsChar();//Конструктор по умолчанию
    unsChar(char _ch);//Конструктор из char
    unsChar(int _chKod);//Конструктор из int
    unsChar(const unsChar& _ch);//Конструктор копирования


    operator char();//Перегрузка оператора преобразования в char
    operator int() const;//Перегрузка оператора преобразования в int

    unsChar operator -() const;//Перегрузка унарного минуса

    char ToChar() const;//Метод, возвращающий ch

private:
    unsigned char ch;//unsigned char, над которым делается надстройка
};

const unsChar operator+(const unsChar& left, const unsChar& right);//Перегрузка оператора "бинарный +"
const unsChar operator*(const unsChar& left, const int& right);//Перегрузка оператора "бинарное *"

#endif // UNSCHAR_H
