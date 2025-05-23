/*
Return the number of times the digit 7 appears in integers less than n which are divisible by 11 or 13.
>>> fizz_buzz(50)
0
>>> fizz_buzz(78)
2
>>> fizz_buzz(79)
3
*/
#include<stdio.h>
using namespace std;
int fizz_buzz(int n){

    int count=0;
    for (int i=0;i<n;i++)
    if (i%11==0 or i%13==0)
    {
        int q=i;
        while (q>0)
        {
            if (q%10==7) count+=1;
            q=q/10;
        }
    } 
    return count;
}
