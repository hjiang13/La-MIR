/*
Write a function that takes a vector of numbers as input and returns 
the number of elements in the vector that are greater than 10 and both 
first and last digits of a number are odd (1, 3, 5, 7, 9).
For example:
specialFilter({15, -73, 14, -15}) => 1 
specialFilter({33, -2, -3, 45, 21, 109}) => 2
*/
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
int specialFilter(vector<int> nums){

    int num=0;
    for (int i=0;i<nums.size();i++)
    if (nums[i]>10)
    {
        string w=to_string(nums[i]);
        if (w[0]%2==1 and w[w.length()-1]%2==1) num+=1;
    }
    return num;
}
