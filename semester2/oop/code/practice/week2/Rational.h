#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <stdexcept>
#include <cmath>

class Rational {
private:
    int numerator;
    unsigned int denominator;
    void simplify();
public:
    Rational(int numerator, unsigned denominator);
    void print() const;
    bool isInteger() const;
    Rational add(const Rational& rhs) const;
    Rational subtract(const Rational& rhs) const;
    Rational multiply(const Rational& rhs) const;
    Rational divide(const Rational& rhs) const;
    int floor() const;
    int ceil() const;
};

void Rational::simplify() {
    if(this->numerator % 2 == 0 && this->denominator % 2 == 0){
        this->denominator/=2;
        this->numerator/=2;
    }

    for(int i = 2; i <= sqrt(this->numerator) && i <= sqrt(this->denominator); ++i) {
        if(this->denominator % i == 0 && this->numerator % i == 0) {
            this->denominator/=i;
            this->numerator/=i;
            i=1;
        }
    }
}

Rational::Rational(int numerator, unsigned denominator) : numerator(numerator) {
    if(denominator == 0) throw std::invalid_argument("Denominator cannot be 0!");
    this->denominator = denominator;

    simplify();
}

void Rational::print() const {
    std::cout << this->numerator << "/" << this->denominator;
}

bool Rational::isInteger() const {
    return this->denominator == 1;
}

Rational Rational::add(const Rational& rhs) const {
    int newNum = this->numerator*rhs.denominator + this->denominator*rhs.numerator;
    int newDen = this->denominator*rhs.denominator;

    return Rational(newNum, newDen);
}

Rational Rational::subtract(const Rational& rhs) const {
    int newNum = this->numerator*rhs.denominator - this->denominator*rhs.numerator;
    int newDen = this->denominator*rhs.denominator;

    return Rational(newNum, newDen);
}

Rational Rational::multiply(const Rational&  rhs) const {
    return Rational(this->numerator*rhs.numerator, this->denominator*rhs.denominator);
}

Rational Rational::divide(const Rational&  rhs) const {
    if(rhs.numerator == 0) throw std::invalid_argument("Cannot devide by 0!");
    return Rational(this->numerator*rhs.denominator, this->denominator*rhs.numerator);
}

int Rational::floor() const {
    if(this->denominator == 1) return this->numerator;

    if(this->numerator > 0) {
        if(this->numerator < this->denominator) return 0;
        return (this->numerator - (this->numerator % this->denominator)) / this->denominator;
    }

    if(this->numerator*(-1) < this->denominator) return -1;

    return (this->numerator - (int) (this->denominator - (this->numerator * (-1) % this->denominator))) / (int) this->denominator; 
}

int Rational::ceil() const {
    if(this->denominator == 1) return this->numerator;

    if(this->numerator > 0) {
        if(this->numerator < this->denominator) return 1;
        return (this->numerator + (this->denominator - this->numerator % this->denominator)) / this->denominator;
    }
    
    if(this->numerator*(-1) < this->denominator) return 0;
    
    return (this->numerator + (int) ((this->numerator * (-1)) % this->denominator)) / (int) this->denominator;
}

#endif