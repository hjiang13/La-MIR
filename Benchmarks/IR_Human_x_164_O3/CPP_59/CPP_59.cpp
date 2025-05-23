/*
Return the largest prime factor of n. Assume n > 1 and is not a prime.
>>> largest_prime_factor(13195)
29
>>> largest_prime_factor(2048)
2
*/
#include<stdio.h>
using namespace std;
int largest_prime_factor(int n){

    for (int i=2;i*i<=n;i++)
    while (n%i==0 and n>i)  n=n/i;
    return n;
}
