/*
You are given a non-empty vector of positive integers. Return the greatest integer that is greater than 
zero, and has a frequency greater than or equal to the value of the integer itself. 
The frequency of an integer is the number of times it appears in the vector.
If no such a value exist, return -1.
Examples:
    search({4, 1, 2, 2, 3, 1}) == 2
    search({1, 2, 2, 3, 3, 3, 4, 4, 4}) == 3
    search({5, 5, 4, 4, 4}) == -1
*/
#include<stdio.h>
#include<vector>
using namespace std;
int search(vector<int> lst){

    vector<vector<int>> freq={};
    int max=-1;
    for (int i=0;i<lst.size();i++)
    {
        bool has=false;
        for (int j=0;j<freq.size();j++)
            if (lst[i]==freq[j][0]) 
            {
            freq[j][1]+=1;
            has=true;
            if (freq[j][1]>=freq[j][0] and freq[j][0]>max) max=freq[j][0];
            }
        if (not(has)) 
        {
        freq.push_back({lst[i],1});
        if (max==-1 and lst[i]==1) max=1;
        }
    }
    return max;
}
