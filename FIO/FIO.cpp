#include "FIO.h"

FIO::FIO()
{
	this->fio.push_back("");
}

FIO::FIO(string smth)
{
	this->fio.push_back(smth);
}

FIO::FIO(FIO& copy)
{
	this->fio = copy.fio;
}

FIO::~FIO()
{

}

ostream& operator<< (ostream& out, FIO& copying)
{
	copy(copying.fio.begin(), copying.fio.end(), ostream_iterator<string>(out, ""));
	return out;
}

istream& operator >> (istream& in, FIO& copying)
{
	string buf;
	in >> buf;
	copying.fio.push_back(buf);
	return in;
}
