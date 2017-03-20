#include <iostream>
#include "complexNum.cpp"
int main ()
{
    ComplexNumber a;
    a.print();
    ComplexNumber b(2,5);
    b.print();
    ComplexNumber c(3,2);
    c.print();
    b*=c;
    b.print();
    a = b + c;
    a.print();
    a = b * c;
    a.print();
    return 0;
}
