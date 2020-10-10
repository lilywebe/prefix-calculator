#include <iostream>
#include <math.h>
#include <string.h>
#include "fraction.hpp"
#include "evaluate.hpp"
using namespace std;
int main()
{
    string eq="";
    string rest="";

    do
    {
        cout<< "Type in your equation"<<endl;
        getline(cin,eq);
        int check=eq.find_first_not_of(" ");
        eq[check]=tolower(eq[check]);
        if(eq[check]=='q'||eq[check]=='e')
        {
            break;
        }
        Fraction answer=evaluate(eq,rest);
        answer=reduce(answer);
        if(answer.isFraction==true)
        {
            cout<<toString(answer)<<endl;
            toDecimal(answer);
            cout<<answer.decimal<<endl;
        }
        else
        {
            cout<<toString(answer)<<endl;
        }
        rest="";
    }
    while(true);

    return 0;
}
