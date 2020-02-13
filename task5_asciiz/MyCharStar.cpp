#include "MyCharStar.h"

MyCharStar::MyCharStar()
{
	this->star = "";
}
MyCharStar::MyCharStar(int n)
{
	star = new  char[n];
}
MyCharStar::MyCharStar(char* str)
{
	star = new  char[strlen(str) + 1];
	strcpy(star, str);
}
MyCharStar::MyCharStar(int n, char* str)
{
    star = new  char[n];
    strcpy(star, str);
}
MyCharStar::MyCharStar(const MyCharStar& Star)
{
    
    star = new  char[strlen(Star.star) + 1];
    strcpy(star, Star.star);
}
MyCharStar::~MyCharStar()
{
    delete[] star;
}

MyCharStar& MyCharStar::operator = (char* str)
{

    star = new  char[strlen(str) + 1];
    strcpy(star, str);
	return *this;
}

MyCharStar& MyCharStar::operator = (const MyCharStar& Star)
{

    star = new  char[strlen(Star.star) + 1];
    strcpy(star, Star.star);
	return *this;
}

MyCharStar MyCharStar::operator + (char* str)
{
	char* buf = new  char[strlen(star) + strlen(str) + 1];
	strcpy(buf, this->star);
	strcat(buf, str);
    MyCharStar n(buf);
    return n;
}

MyCharStar MyCharStar::operator + (const MyCharStar& Star)
{
    char* buf = new  char[strlen(star) + strlen(Star.star) + 1];
	strcpy(buf, this->star);
	strcat(buf, Star.star);
    MyCharStar n(buf);
    return n;
}

char& MyCharStar::operator [](const int &index)
{
	if (index < 0 || index > int(strlen(this->star)))
	{
		cout << "ERROR!!! OUT OF RANGE!!!";
		_getch();
		exit(1);
	}
	else
		return this->star[index];
}

ostream& operator << (ostream& outs, MyCharStar& Star) //вывод
{
	outs << Star.star;
	return outs;
}
