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

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(order_by_points({1, 11, -1, -11, -12}) , {-1, -11, 1, -12, 11}));
    assert (issame(order_by_points({1234,423,463,145,2,423,423,53,6,37,3457,3,56,0,46}) , {0, 2, 3, 6, 53, 423, 423, 423, 1234, 145, 37, 46, 56, 463, 3457}));
    assert (issame(order_by_points({}) , {}));
    assert (issame(order_by_points({1, -11, -32, 43, 54, -98, 2, -3}) , {-3, -32, -98, -11, 1, 2, 43, 54}));
    assert (issame(order_by_points({1,2,3,4,5,6,7,8,9,10,11}) , {1, 10, 2, 11, 3, 4, 5, 6, 7, 8, 9}));
    assert (issame(order_by_points({0,6,6,-76,-21,23,4}) , {-76, -21, 0, 4, 23, 6, 6}));
    
}
