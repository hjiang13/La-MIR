Sure, here's the decompiled C++ source code for the provided IR code:

#include<stdio.h>
#include<string>
using namespace std;

int largest_prime_factor(int n){

    if (n<4) return n;

    int i=2;
    while (i*i<=n){
        if (n%i==0) n=n/i;
        else i++;
    }
    return n;
}

int main(){
    int n;
    cin>>n;
    cout<<largest_prime_factor(n)<<endl;
    return 0;
}

Note that the decompiled code may not be identical to the original source code, but it should produce the same output for the same input.