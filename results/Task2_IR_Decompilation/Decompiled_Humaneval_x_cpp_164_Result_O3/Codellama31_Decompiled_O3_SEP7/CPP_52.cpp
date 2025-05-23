Sure, here's the decompiled C++ source code for the provided IR code:

#include<stdio.h>
#include<string>
using namespace std;
bool below_threshold(vector<int> numbers, int threshold){

    int count=0;
    for (int i=0;i<numbers.size();i++)
    {
        if (numbers[i]<threshold) count+=1;
        if (count>1) return false;
    }
    return true;
}


Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.