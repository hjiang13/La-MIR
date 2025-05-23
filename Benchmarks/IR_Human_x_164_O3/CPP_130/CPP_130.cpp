/*
Everyone knows Fibonacci sequence, it was studied deeply by mathematicians in 
the last couple centuries. However, what people don't know is Tribonacci sequence.
Tribonacci sequence is defined by the recurrence:
tri(1) = 3
tri(n) = 1 + n / 2, if n is even.
tri(n) =  tri(n - 1) + tri(n - 2) + tri(n + 1), if n is odd.
For example:
tri(2) = 1 + (2 / 2) = 2
tri(4) = 3
tri(3) = tri(2) + tri(1) + tri(4)
       = 2 + 3 + 3 = 8 
You are given a non-negative integer number n, you have to a return a vector of the 
first n + 1 numbers of the Tribonacci sequence.
Examples:
tri(3) = {1, 3, 2, 8}
*/
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> tri(int n){

    vector<int> out={1,3};
    if (n==0) return {1};
    for (int i=2;i<=n;i++)
    {
        if (i%2==0) out.push_back(1+i/2);
        else out.push_back(out[i-1]+out[i-2]+1+(i+1)/2);
    }
    return out;
}
