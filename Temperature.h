//
// Created by u211-07 on 10.04.2018.
//

#ifndef UNTITLED_TEMPERATURE_H
#include <iostream>
#include <cassert>
#include <sstream>
#define UNTITLED_TEMPERATURE_H
using namespace std;
struct Temperature {
    double value;
    char scale;
};
istream& operator>>(istream& stream,Temperature& Temp);
double convert (double input, char from, char to);
bool operator <(const Temperature& LHS,const Temperature& RHS);
Temperature operator - (const Temperature& LHS, const Temperature& RHS);
Temperature operator /(const Temperature& LHS,const Temperature& RHS);
Temperature operator *(const Temperature& LHS,const Temperature& RHS);
int check(const Temperature& Temp)
#endif //UNTITLED_TEMPERATURE_H
