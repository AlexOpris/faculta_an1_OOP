#include "complex.h"
#pragma once
#include <iostream>

using namespace std;

class complex
{
	private:
		float real;
		float imag;

	public:
		complex();

		complex(float, float);

		~complex();

		float getReal();
		float getImag();
		float setReal(float);
		float setImag(float);

		friend ostream& operator<< (ostream& os, complex& c);
		friend istream& operator>> (istream& in, complex& c);

		friend complex operator+ (complex& c1, complex& c2);

};

complex operator+ (complex& c1, complex& c2)
{
	complex c3;
	c3.real = c1.real + c2.real;
	c3.imag = c1.imag + c2.imag;
	return c3;
}

complex::complex()
{
	real = 0;
	imag = 0;
	cout << "Object created";
}

complex::complex(float r, float i)
{
	real = r;
	imag = i;
	cout << "Object created";
}

complex::~complex()
{
	cout << "Object deleted";
}

float complex::getReal()
{
	return real;
}

float complex::getImag()
{
	return imag;
}

float complex::setReal(float r)
{
	real = r;
}

float complex::setImag(float i)
{
	imag = i;
}

ostream& operator<< (ostream& os, complex& c)
{

	os << "Real part is: " << c.real << endl << "Imaginary part is: " << c.imag;
	return os;
}

istream& operator>> (istream& in, complex& c)
{
	cout << "Introduce real and imaginary part: ";
	in >> c.real >> c.imag;
	return in;
}
