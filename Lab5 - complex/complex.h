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

