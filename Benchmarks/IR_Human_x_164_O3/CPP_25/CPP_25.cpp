/*
Return vector of prime factors of given integer in the order from smallest to largest.
Each of the factors should be vectored number of times corresponding to how many times it appeares in factorization.
Input number should be equal to the product of all factors
>>> factorize(8)
{2, 2, 2}
>>> factorize(25)
{5, 5}
>>> factorize(70)
{2, 5, 7}
*/
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> factorize(int n){

    vector<int> out={};
    for (int i=2;i*i<=n;i++)
        if (n%i==0)
        {
            n=n/i;
            out.push_back(i);
            i-=1;
        }
    out.push_back(n);
    return out;
}
