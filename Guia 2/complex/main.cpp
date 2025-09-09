#include <iostream>

class Complex
{
    friend std::ostream& operator<< (std::ostream& outStream, Complex z);

private:
    int real;
    int imaginary;

public:
    Complex(int newReal = 0, int newImaginary = 0) : real(newReal), imaginary(newImaginary) {}
    int getReal() { return real; }
    int getImaginary() { return imaginary; }

    Complex operator+ (Complex& z)
    {
        return Complex(this->real + z.real, this->imaginary + z.imaginary);
    }
    Complex operator- (Complex& z)
    {
        return Complex(this->real - z.real, this->imaginary - z.imaginary);
    }
};

std::ostream& operator<< (std::ostream& outStream, Complex z)
{
    outStream << z.real << " + " << z.imaginary << " j";
    return outStream;
}

int main()
{
    Complex a(1,2);
    Complex b(4,5);

    Complex z = a + b;
    std::cout << z << std::endl;
}