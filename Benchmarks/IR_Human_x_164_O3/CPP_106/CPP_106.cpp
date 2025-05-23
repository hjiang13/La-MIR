/*
Implement the function f that takes n as a parameter,
and returns a vector of size n, such that the value of the element at index i is the factorial of i if i is even
or the sum of numbers from 1 to i otherwise.
i starts from 1.
the factorial of i is the multiplication of the numbers from 1 to i (1 * 2 * ... * i).
Example:
f(5) == {1, 2, 6, 24, 15}
*/
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> f(int n){

    int sum=0,prod=1;
    vector<int> out={};
    for (int i=1;i<=n;i++)
    {
        sum+=i;
        prod*=i;
        if (i%2==0) out.push_back(prod);
        else out.push_back(sum);
    } 
    return out;
}
