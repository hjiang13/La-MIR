/*
Given a positive floating point number, it can be decomposed into
and integer part (largest integer smaller than given number) and decimals
(leftover part always smaller than 1).

Return the decimal part of the number.
>>> truncate_number(3.5)
0.5
*/
#include<stdio.h>
#include<math.h>
using namespace std;
float truncate_number(float number){

    return number-int(number);
}
