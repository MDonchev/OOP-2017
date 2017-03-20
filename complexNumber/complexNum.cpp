#include <iostream>
#include "complexNum.h"
inline float ComplexNumber::getReal() const
{
    return real;
}
inline float ComplexNumber::getImag() const
{
    return imag;
}
ComplexNumber :: ComplexNumber(float _real, float _imag)
{
    real = _real;
    imag = _imag;
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other)
{
    return ComplexNumber(real*other.getReal() - imag*other.getImag(),
                         real*other.getImag() + imag*other.getReal());
}
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other)
{
    return ComplexNumber(real+other.getReal(), imag+other.getImag());
}
ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other)
{
    *this = ComplexNumber(real*other.getReal() - imag*other.getImag(),
                         real*other.getImag() + imag*other.getReal());
    return *this;
}
void ComplexNumber::print() const
{
    std::cout<<'('<<real<<','<<imag<<')'<<std::endl;
}
