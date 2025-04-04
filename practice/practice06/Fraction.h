#pragma once

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Fraction 
{
private:
    int num;  
    int den; 

    void simplify();  

public:

    Fraction();
    Fraction(int n, int d);

    
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int n);
    void setDenominator(int d);

    
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
};

#endif