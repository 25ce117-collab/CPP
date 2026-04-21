#include <iostream>
using namespace std;

class Complex
{
    float real;
    float imag;

public:
    Complex(float r = 0.0, float i = 0.0) :
        real(r), imag(i) {}

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    void display() const
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(2.5, 3.5);
    Complex c2(1.5, 4.5);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    cout << "First complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    cout << "Sum of the two complex numbers: ";
    sum.display();

    cout << "Difference of the two complex numbers: ";
    difference.display();

    return 0;
}
