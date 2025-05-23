/*
Write a function which sorts the given vector of integers
in ascending order according to the sum of their digits.
Note: if there are several items with similar sum of their digits,
order them based on their index in original vector.

For example:
>>> order_by_points({1, 11, -1, -11, -12}) == {-1, -11, 1, -12, 11}
>>> order_by_points({}) == {}
*/
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
vector<int> order_by_points(vector<int> nums){

    vector<int> sumdigit={};
    for (int i=0;i<nums.size();i++)
    {
        string w=to_string(abs(nums[i]));
        int sum=0;
        for (int j=1;j<w.length();j++)
            sum+=w[j]-48;
        if (nums[i]>0) sum+=w[0]-48;
        else sum-=w[0]-48;
        sumdigit.push_back(sum);
    }
    int m;
    for (int i=0;i<nums.size();i++)
    for (int j=1;j<nums.size();j++)
    if (sumdigit[j-1]>sumdigit[j])
    {
        m=sumdigit[j];sumdigit[j]=sumdigit[j-1];sumdigit[j-1]=m;
        m=nums[j];nums[j]=nums[j-1];nums[j-1]=m;
    }
     
    return nums;
}
