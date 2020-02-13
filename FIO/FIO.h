#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class FIO
{
//private:
	
public:
	vector<string> fio;
	FIO();
	FIO(string smth);
	FIO(FIO& copy);
	~FIO();
	friend ostream& operator<< (ostream& out, FIO& copy);
	friend istream& operator >> (istream& out, FIO& copy);
};
