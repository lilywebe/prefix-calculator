#pragma once
#include <string>
struct Fraction
{
    bool isFraction=true;
    int numerator;
    int denominator;
    float decimal;
};
Fraction add(Fraction a, Fraction b);
Fraction multiply(Fraction a, Fraction b);
Fraction subtract (Fraction a, Fraction b);
Fraction divide(Fraction a, Fraction b);
Fraction power(Fraction a, Fraction b);
Fraction reduce(Fraction frac);
Fraction stringtoFraction(std::string str);
std::string toString(Fraction frac);
Fraction findCos(Fraction frac);
Fraction findSin(Fraction frac);
Fraction toDecimal(Fraction& frac);
