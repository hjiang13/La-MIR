/*
Write a function count_nums which takes a vector of integers and returns
the number of elements which has a sum of digits > 0.
If a number is negative, then its first signed digit will be negative:
e.g. -123 has signed digits -1, 2, and 3.
>>> count_nums({}) == 0
>>> count_nums({-1, 11, -11}) == 1
>>> count_nums({1, 1, 2}) == 3
*/
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
int count_nums(vector<int> n){

    int num=0;
    for (int i=0;i<n.size();i++)
        if (n[i]>0) num+=1;
        else
        {
            int sum=0;
            int w;
            w=abs(n[i]);
            while (w>=10)
            {
                sum+=w%10;
                w=w/10;
            }
            sum-=w;
            if (sum>0) num+=1;
        }
    return num;
}
