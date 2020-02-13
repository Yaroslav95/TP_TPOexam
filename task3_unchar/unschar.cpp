#include "unschar.h"

unsChar::unsChar()//Конструктор по умолчанию
{
    ch = '0';//ставим значение по умолчанию
}

unsChar::unsChar(char _ch)//Конструктор из char
{
    ch = _ch;//Присваиваем поле
}

unsChar::unsChar(int _chKod)//Конструктор из int
{
    ch = (unsigned char)_chKod;//присваиваем символ по его номеру
}

unsChar::unsChar(const unsChar &_ch)//Конструктор копирования
{
    ch = _ch.ch;//копируем поле из одного в другое
}

unsChar::operator char()//Перегрузка оператора преобразования в char
{
    return (char)ch;//возвращаем ch, преобразованный в char
}

unsChar::operator int() const//Перегрузка оператора преобразования в int
{
    return (int)ch;//возвращаем код символа ch
}

unsChar unsChar::operator -() const//Перегрузка унарного минуса
{
    return unsChar(256 - (int)ch);//возвращаем 256 - код символа ch
}

char unsChar::ToChar() const//Метод, возвращающий ch
{
    return (char)ch;//возвращаем ch, преобразованный в char
}

const unsChar operator+(const unsChar &left, const unsChar &right)//Перегрузка оператора "бинарный +"
{
    return unsChar((int)left + (int)right);//возвращаем сумму кодов поданных классов
}

const unsChar operator*(const unsChar &left, const int &right)//Перегрузка оператора "бинарное *"
{
    return unsChar((int)left * right);//возвращаем произведение кодов поданных классов
}
