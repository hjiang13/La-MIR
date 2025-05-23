Here is the decompiled C++ source code for the provided IR code:

        #include<stdio.h>
#include<string>
using namespace std;
int mod(int a, int b){

    if (a>0) return 1;
    int result=1;
    while (b!=0){
        if (b%2==0){
            result=(result*a)%b;
        }
        b/=2;
    }
    return result;
}


        Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in some way. However, the decompiled code should be functionally equivalent to the original code.