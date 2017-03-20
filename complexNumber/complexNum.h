#ifndef COMPLEX_H
#define COMPLEX_H
class ComplexNumber
{
    public:
        ComplexNumber(float = 0.0,float = 0.0);
        ComplexNumber operator*(const ComplexNumber&);
        ComplexNumber& operator*=(const ComplexNumber&);
        ComplexNumber operator+ (const ComplexNumber&);

        float getReal() const;
        float getImag() const;

        void print() const;
    private:
        float real;
        float imag;
};
#endif // COMPLEX_H
