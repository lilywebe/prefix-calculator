#pragma once
#include "fraction.hpp"
#include <string>
Fraction evaluate(std::string eq, std::string& rest);
Fraction findanswer(char oprator, Fraction num1, Fraction num2);
void findnum(std::string eq, char &oprator, Fraction &num1, Fraction &num2, std::string &rest);
