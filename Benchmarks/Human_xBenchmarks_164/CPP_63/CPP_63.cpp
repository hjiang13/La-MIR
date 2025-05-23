/*
The FibFib number sequence is a sequence similar to the Fibbonacci sequnece that's defined as follows:
fibfib(0) == 0
fibfib(1) == 0
fibfib(2) == 1
fibfib(n) == fibfib(n-1) + fibfib(n-2) + fibfib(n-3).
Please write a function to efficiently compute the n-th element of the fibfib number sequence.
>>> fibfib(1)
0
>>> fibfib(5)
4
>>> fibfib(8)
24
*/
#include<stdio.h>
using namespace std;
int fibfib(int n){

    int ff[100];
    ff[0]=0;
    ff[1]=0;
    ff[2]=1;
    for (int i=3;i<=n;i++)
        ff[i]=ff[i-1]+ff[i-2]+ff[i-3];
    return ff[n];

}
