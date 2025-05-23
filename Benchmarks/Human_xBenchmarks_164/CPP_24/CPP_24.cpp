/*
For a given number n, find the largest number that divides n evenly, smaller than n
>>> largest_divisor(15)
5
*/
#include<stdio.h>
using namespace std;
int largest_divisor(int n){

    for (int i=2;i*i<=n;i++)
        if (n%i==0) return  n/i;
    return 1;

}
