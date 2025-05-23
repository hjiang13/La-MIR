/*
Circular shift the digits of the integer x, shift the digits right by shift
and return the result as a string.
If shift > number of digits, return digits reversed.
>>> circular_shift(12, 1)
"21"
>>> circular_shift(12, 2)
"12"
*/
#include<stdio.h>
#include<string>
using namespace std;
string circular_shift(int x,int shift){

    string xs;
    xs=to_string(x);
    if (xs.length()<shift)
    {
        string s(xs.rbegin(),xs.rend());
        return s;
    }
    xs=xs.substr(xs.length()-shift)+xs.substr(0,xs.length()-shift);
    return xs;
}
