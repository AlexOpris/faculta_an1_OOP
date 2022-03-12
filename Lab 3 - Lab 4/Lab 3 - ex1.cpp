#include <iostream>
#include <cmath>

using namespace std;


class complex
{
    float real, imag;

public:
    complex();
    complex(float, float);
    complex add(complex, complex);
    void display(complex);
    complex subtract(complex, complex);
    complex multiply(complex, complex);
    bool equal(complex, complex);
    complex conjugate(complex);
    void multiply_with_scalar(complex, int);
    double magnitude(complex);
    double phase(complex);
    complex divide(complex, complex);
    
    friend std::ostream& operator<< (std::ostream& out, complex& c);
    friend std::istream& operator>> (std::istream& in, complex& c);
};



complex::complex() {
    real = 0;
    imag = 0;
}

complex::complex(float a, float b)
{
    real = a;
    imag = b;
}


void complex::display(complex c)
{
    cout << "The real part is: " << c.real << "\n" << "The imaginary part is: " << c.imag;
}

complex complex::add(complex c1, complex c2)
{  
    complex c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;  
    return c3;
}

complex complex::subtract(complex c1, complex c2)
{
    complex c3;
    c3.real = c1.real - c2.real;
    c3.imag = c1.imag - c2.imag;   
    return c3;
}

complex complex::multiply(complex c1, complex c2)
{
    complex c3;
    c3.real = c1.real * c1.real - c2.imag * c2.imag;
    c3.imag = c1.imag * c2.imag + c1.imag * c2.real;
    return c3;
}

bool complex::equal(complex c1, complex c2)
{
    if (c1.real == c2.real && c2.imag == c2.imag)
        return true;
    else
        return false;
}

complex complex::conjugate(complex c)
{
    c.imag = c.imag * -1;
    return c;
}

void complex::multiply_with_scalar(complex c, int n)
{
    c.real = c.real * n;
    c.imag = c.imag * n;
}


double complex::magnitude(complex c)
{
    double res = c.real * c.real + c.imag * c.imag;
    return sqrt(res);
}

double complex::phase(complex c)
{
    return tan(c.real/c.imag);
}
/*
void toPolar(complex c, float* r, float* theta)
{
    
}
*/

complex complex::divide(complex c1, complex c2)
{
    complex conj;
    conj = conjugate(c2);
    c1 = multiply(c1, conj);
    c2 = multiply(c2, conj);
    multiply_with_scalar(c1, 1 / (c2.real - c2.imag));
    return c1;

}

int main()
{
    complex c1(1, 3);
    complex c2(4, 2);
    
    c1.display(c1);

    cout << "\n";

}
