/*
You are given a vector arr of integers and you need to return
sum of magnitudes of integers multiplied by product of all signs
of each number in the vector, represented by 1, -1 or 0.
Note: return -32768 for empty arr.

Example:
>>> prod_signs({1, 2, 2, -4}) == -9
>>> prod_signs({0, 1}) == 0
>>> prod_signs({}) == -32768
*/
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
int prod_signs(vector<int> arr){

    if (arr.size()==0) return -32768;
    int i,sum=0,prods=1;
    for (i=0;i<arr.size();i++)
    {
        sum+=abs(arr[i]);
        if (arr[i]==0) prods=0;
        if (arr[i]<0) prods=-prods;
   }
   return sum*prods;
}
