#include "Vector.h"
#include "Exceptions.h"

Vector::Vector() //к-р по умолчанию
{
	dim = 0;
	dat = NULL;
}

Vector::Vector(int d) //к-р иннициализации
{
	dim = d;
	dat = new float[dim];
	for (int i = 0; i < dim; i++)
	{
		dat[i] = 0;
	}
}

Vector::Vector(int d, float *insides) //к-р иннициализации
{
	dim = d;
	dat = new float[dim];
	for (int i = 0; i < dim; ++i)
	{
		dat[i] = insides[i];
		if (dat[i] < INT_MIN || dat[i] > INT_MAX)
		{
			throw new OutOfRange(dat[i], '0');
		}
	}
}

Vector::Vector(Vector& vect) //к-р копии
{
	dim = vect.dim;
	dat = new float[dim];
	for (int i = 0; i < dim; ++i)
		dat[i] = vect.dat[i];
}

Vector::~Vector() //деструктор
{
	if (dat)
	{
		delete[] dat;
	}
}

Vector Vector::operator = (Vector& vect) //оп присваивания
{
	dim = vect.dim;
	dat = new float[dim];
	for (int i = 0; i < dim; ++i)
		dat[i] = vect.dat[i];
	return *this;
}

bool Vector::operator == (Vector& vect)
{
	if (dim != vect.dim)
	{
		throw new DimMismatch(dim, vect.dim);
	}
	for (int i = 0; i < dim; ++i)
	{
		if (dat[i] == vect.dat[i])
		{
			return true;
		}
	}
	return false;
}

bool Vector::operator != (Vector& vect)
{
	if (dim != vect.dim)
	{
		throw new DimMismatch(dim, vect.dim);
	}
	for (int i = 0; i < dim; ++i)
	{
		if (dat[i] != vect.dat[i])
		{
			return true;
		}
	}
	return false;
}

Vector Vector::operator + (const Vector vect) //сумма векторов
{
	Vector bufv(dim);
	if (bufv.dim != vect.dim)
	{
		throw new DimMismatch(bufv.dim, vect.dim);
	}
	for (int i = 0; i < dim; ++i)
	{
		bufv.dat[i] = dat[i] + vect.dat[i];
		if (bufv.dat[i] < INT_MIN || bufv.dat[i] > INT_MAX)
		{
			throw new OutOfRange(dat[i], '+', vect.dat[i]);
		}
	}
	return bufv;
}

Vector Vector::operator - () //унарный минус
{
	Vector bufv(dim);
	for (int i = 0; i < dim; ++i)
	{
		bufv.dat[i] = -dat[i];
	}
	return bufv;
}

Vector Vector::operator - (const Vector vect) //разность векторов
{
	Vector bufv(dim);
	if (bufv.dim != vect.dim)
	{
		throw new DimMismatch(bufv.dim, vect.dim);
	}
	for (int i = 0; i < dim; ++i)
	{
		bufv.dat[i] = dat[i] - vect.dat[i];
		if (bufv.dat[i] < INT_MIN || bufv.dat[i] > INT_MAX)
		{
			throw new OutOfRange(dat[i], '-', vect.dat[i]);
		}
	}
	return bufv;
}

Vector Vector::operator * (const float n)
{
	Vector bufv = *this;
	for (int i = 0; i < bufv.dim; ++i)
	{
		bufv.dat[i] = bufv.dat[i] * n;
		if (bufv.dat[i] < INT_MIN || bufv.dat[i] > INT_MAX)
		{
			throw new OutOfRange(bufv.dat[i], '*', n);
		}
	}
	return bufv;
}

Vector Vector::operator * (const Vector vect) //произведение соотв координат векторов
{
	Vector bufv(dim);
	if (dim != vect.dim)
	{
		throw new DimMismatch(dim, vect.dim);
	}
	for (int i = 0; i < dim; ++i)
	{
		bufv.dat[i] = dat[i] * vect.dat[i];
		if (bufv.dat[i] < INT_MIN || bufv.dat[i] > INT_MAX)
		{
			throw new OutOfRange(dat[i], '*', vect.dat[i]);
		}
	}
	return bufv;
}

float Vector::operator , (const Vector vect) //скалярное умножение
{
	float sum = 0;
	if (dim != vect.dim)
	{
		throw new DimMismatch(dim, vect.dim);
	}
	for (int i = 0; i < dim; ++i)
	{
		sum += dat[i] * vect.dat[i];
		if (sum < INT_MIN || sum > INT_MAX)
		{
			throw new OutOfRange(sum, '+', (dat[i] * vect.dat[i]));
		}
	}
	return sum;
}

float& Vector::operator [](const int &index)
{
	if (index < 0 || index > dim)
	{
		throw new DimMismatch(dim, index, '1');
	}
	return this->dat[index];
}

Vector operator * (float n, Vector vect) // умножение числа на вектор
{
	for (int i = 0; i < vect.dim; ++i)
	{
		vect.dat[i] = n * vect.dat[i];
		if (vect.dat[i] < INT_MIN || vect.dat[i] > INT_MAX)
		{
			throw new OutOfRange(n, '*', vect.dat[i]);
		}
	}
	return vect;
}

Vector operator / (Vector vect, float m) // деление на число
{
	if (m == 0)
	{
		throw new DivByZero(vect);
	}
	for (int i = 0; i < vect.dim; ++i)
	{
		vect.dat[i] = vect.dat[i] / m;
		if (vect.dat[i] < INT_MIN || vect.dat[i] > INT_MAX)
		{
			throw new OutOfRange(vect.dat[i], '/', m);
		}
	}
	return vect;
}

ostream& operator << (ostream& outs, Vector& vect) //вывод
{
	for (int i = 0; i < vect.dim; ++i)
	{
		if (i)
		{
			outs << ",";
		}
		outs << vect.dat[i];
	}
	return outs;
}

