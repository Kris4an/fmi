#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H
#include <iostream>

struct ComplexNumber {
    double Re;
    double Im;

    void print() const;
    ComplexNumber add(ComplexNumber a) const;
    ComplexNumber subtract(ComplexNumber a) const;
    ComplexNumber multiply(ComplexNumber a) const;
};

void ComplexNumber::print() const {
    std::cout<< "( " << Re << " + " << Im << "i )";
}

ComplexNumber ComplexNumber::add(ComplexNumber a) const{
    return ComplexNumber {Re + a.Re, Im + a.Im};
}
ComplexNumber ComplexNumber::subtract(ComplexNumber a) const{
    return ComplexNumber {Re - a.Re, Im - a.Im};
}
ComplexNumber ComplexNumber::multiply(ComplexNumber a) const{
    return ComplexNumber {Re * a.Re - Im * a.Im, Re * a.Im + a.Re * Im};
}

#endif