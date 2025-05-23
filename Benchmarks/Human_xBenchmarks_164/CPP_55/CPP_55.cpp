/*
Return n-th Fibonacci number.
>>> fib(10)
55
>>> fib(1)
1
>>> fib(8)
21
*/
#include<stdio.h>
using namespace std;
int fib(int n){

    int f[1000];
    f[0]=0;f[1]=1;
    for (int i=2;i<=n; i++)
    f[i]=f[i-1]+f[i-2];
    return f[n];
}
