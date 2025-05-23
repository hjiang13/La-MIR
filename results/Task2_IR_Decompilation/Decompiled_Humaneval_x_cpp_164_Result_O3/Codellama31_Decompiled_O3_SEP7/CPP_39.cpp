Sure, here's the decompiled C++ source code for the provided IR code:

#include<stdio.h>
#include<string>
using namespace std;
int prime_fib(int n){
    int a=1, b=2, c=0, d=0;
    while(c<n){
        d=a+b;
        a=b;
        b=d;
        c++;
    }
    return b;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",prime_fib(n));
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways. However, the decompiled code should be functionally equivalent to the original code.