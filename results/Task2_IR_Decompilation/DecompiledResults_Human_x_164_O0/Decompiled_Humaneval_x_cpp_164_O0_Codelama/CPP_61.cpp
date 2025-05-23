Sure, here's the decompiled C++ source code for the provided IR code:

#include<stdio.h>
#include<string>
using namespace std;
bool correct_bracketing(string brackets){

    int level=0;
    for (int i=0;i<brackets.length();i++)
    {
        if (brackets[i]=='(') level+=1;
        if (brackets[i]==')') level-=1;
        if (level<0) return false;
    }
    if (level!=0) return false;
    return true;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should have the same behavior and functionality.