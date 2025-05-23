/*
Given a vector of non-negative integers, return a copy of the given vector after sorting,
you will sort the given vector in ascending order if the sum( first index value, last index value) is odd,
or sort it in descending order if the sum( first index value, last index value) is even.

Note:
* don't change the given vector.

Examples:
* sort_vector({}) => {}
* sort_vector({5}) => {5}
* sort_vector({2, 4, 3, 0, 1, 5}) => {0, 1, 2, 3, 4, 5}
* sort_vector({2, 4, 3, 0, 1, 5, 6}) => {6, 5, 4, 3, 2, 1, 0}
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sort_array(vector<int> array){

    if (array.size()==0) return {};
    if ((array[0]+array[array.size()-1]) %2==1)
    {
        sort(array.begin(),array.end());
        return array;
    }
    else
    {
        sort(array.begin(),array.end());
        vector<int> out={};
        for (int i=array.size()-1;i>=0;i-=1)
            out.push_back(array[i]);
        return out;
    }

}
