#include "evaluate.hpp"
#include <string.h>
#include <iostream>
using namespace std;
Fraction findanswer(char oprator, Fraction num1, Fraction num2)
{
    switch(oprator)
    {
    case '+':
        return add(num1, num2);
        break;
    case '-':
        return subtract(num1, num2);
        break;
    case '/':
        return divide(num1, num2);
        break;
    case '*':
        return multiply(num1, num2);
        break;
    case '^':
        return power(num1,num2);
        break;
    case 's':
        return findSin(num1);
        break;
    case 'c':
        return findCos(num1);
        break;
    case 'n':
        return num1;
        break;
    }
}
void findnum(string eq, char &oprator, Fraction &num1, Fraction &num2, string &rest)
{
    int startPos=eq.find_first_not_of(" ");
    oprator=eq[startPos];
    if(!isdigit(oprator))
    {
        if(oprator!='s'&&oprator!='c')
        {
            num1=evaluate(eq.substr(startPos+1),rest);
            num2=evaluate(rest,rest);
        }
        else
        {
            num1=evaluate(eq.substr(startPos+1),rest);
        }
    }
    else
    {
        //n for number i guess lol i couldn't come up with anything better
        oprator='n';
        int lastNumber=startPos;
        while(lastNumber<eq.length())
        {
            if(isdigit(eq[lastNumber])==false&&eq[lastNumber]!='.')
            {
                break;
            }
            else
            {
                lastNumber++;
            }

        }
        if(lastNumber!=eq.length())
        {
            rest=eq.substr(lastNumber,eq.length()-lastNumber);
        }
        else
        {
            rest="";
        }
        num1=stringtoFraction(eq.substr(startPos,lastNumber - startPos));
    }
}
Fraction evaluate(string eq, string& rest)
{
    char oprator;
    Fraction num1,num2;
    findnum(eq,oprator,num1,num2,rest);
    return findanswer(oprator,num1,num2);
}
