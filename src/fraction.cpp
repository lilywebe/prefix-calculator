#include "fraction.hpp"
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;
Fraction add(Fraction a, Fraction b)
{
    Fraction added;
    if(a.isFraction==true&&b.isFraction==true)
    {
        added.denominator=a.denominator*b.denominator;
        added.numerator=((a.denominator*b.numerator)+(b.denominator*a.numerator));
    }
    else
    {
        toDecimal(a);
        toDecimal(b);
        added.decimal=a.decimal+b.decimal;
        added.isFraction=false;
    }
    return added;
}
Fraction multiply(Fraction a, Fraction b)
{
    Fraction multiplied;
    if(a.isFraction==true&&b.isFraction==true)
    {
        multiplied.numerator=a.numerator*b.numerator;
        multiplied.denominator=a.denominator*b.denominator;
    }
    else
    {
        toDecimal(a);
        toDecimal(b);
        multiplied.decimal=a.decimal*b.decimal;
        multiplied.isFraction=false;
    }
    return multiplied;
}
Fraction subtract (Fraction a, Fraction b)
{
    Fraction negative;
    negative.numerator=-1;
    negative.denominator=1;
    return add(a, multiply(b, negative));
}
Fraction divide(Fraction a, Fraction b)
{
    Fraction reciprocal;
    if(b.isFraction)
    {
        reciprocal.numerator=b.denominator;
        reciprocal.denominator=b.numerator;
    }
    else
    {
        reciprocal.isFraction=false;
        reciprocal.decimal=1/b.decimal;
    }
    return(multiply(a,reciprocal));
}
Fraction power(Fraction a, Fraction b)
{
    toDecimal(a);
    toDecimal(b);
    Fraction answer;
    answer.isFraction=false;
    answer.decimal=pow(a.decimal,b.decimal);
    return(answer);
}
Fraction reduce(Fraction frac)
{

    int gcd;
    if(frac.isFraction==true)
    {
        if (frac.numerator<0&&frac.denominator<0)
        {
            frac.numerator*=-1;
            frac.denominator*=-1;
        }
        else if(frac.denominator<0)
        {
            frac.numerator*=-1;
            frac.denominator*=-1;
        }
        else if(frac.denominator==0)
        {
            frac.numerator=0;
        }
        else if(frac.numerator==0)
        {
            frac.denominator=1;
        }
        if(frac.numerator!=0)
        {
            for(int i=1; ((i<=frac.numerator)&&(i<=frac.denominator)); i++)
            {
                if((frac.numerator%i==0)&&(frac.denominator%i==0))
                {
                    gcd=i;
                }
            }

            frac.numerator/=gcd;
            frac.denominator/=gcd;
        }
    }
    return frac;
}
string toString(Fraction frac)
{
    string fractiontostr ="";
    if(frac.isFraction==true)
    {
        fractiontostr+=to_string(frac.numerator);
        fractiontostr+="/";
        fractiontostr+=to_string(frac.denominator);
    }
    else
    {
        fractiontostr+=to_string(frac.decimal);
    }
    return fractiontostr;
}
Fraction stringtoFraction(string str)
{
    Fraction newfraction;
    int pos=0;
    bool isDecimal=false;
    while(pos<str.length())
    {
        if(str[pos]=='.')
        {
            isDecimal=true;
            break;
        }
        pos++;
    }
    if(isDecimal)
    {
        newfraction.decimal=stof(str);
        newfraction.isFraction=false;
    }
    else
    {
        newfraction.numerator=stoi(str);
        newfraction.denominator=1;
    }
    return newfraction;
}
Fraction findSin(Fraction frac)
{
    Fraction sined;
    toDecimal(frac);
    sined.decimal=sin(frac.decimal);
    return sined;
}
Fraction findCos(Fraction frac)
{
    Fraction cosed;
    toDecimal(frac);
    cosed.decimal=sin(frac.decimal);
    return cosed;
}
Fraction toDecimal(Fraction& frac)
{
    if (frac.isFraction==true)
    {
        frac.decimal=(float)frac.numerator/(float)frac.denominator;
        frac.isFraction=false;
    }
    return frac;
}
