Here is the decompiled C++ source code for the provided IR code:

        #include<stdio.h>
#include<string>
using namespace std;
int multiply(int a, int b){

    int result=0;
    int sign=1;
    if (a<0) {
        a=-a;
        sign=-sign;
    }
    if (b<0) {
        b=-b;
        sign=-sign;
    }
    while (a>0) {
        result+=b;
        a-=1;
    }
    return result*sign;
}


        Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code, and can be used as a starting point for reverse engineering or debugging purposes.