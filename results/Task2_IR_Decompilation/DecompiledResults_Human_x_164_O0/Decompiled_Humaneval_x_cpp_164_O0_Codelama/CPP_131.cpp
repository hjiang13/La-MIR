Sure, here's the decompiled C++ code for the provided IR code:

        #include<stdio.h>
#include<string>
using namespace std;

int digit(int num){
    string str;
    to_string(str,num);
    int len=str.length();
    int sum=0;
    for(int i=0;i<len;i++){
        if(str[i]=='0') sum=sum*10+str[i]-'0';
    }
    return sum;
}

int main(){
    int num=12345;
    int result=digit(num);
    printf("%d",result);
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should produce the same output and have the same behavior.