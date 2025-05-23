/*
Create a function that returns a vector (a, b), where "a" is
the largest of negative integers, and "b" is the smallest
of positive integers in a vector.
If there is no negative or positive integers, return them as 0.

Examples:
largest_smallest_integers({2, 4, 1, 3, 5, 7}) == {0, 1}
largest_smallest_integers({}) == {0,0}
largest_smallest_integers({0}) == {0,0}
*/
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> largest_smallest_integers(vector<int> lst){

    int maxneg=0,minpos=0;
    for (int i=0;i<lst.size();i++)
    {
        if (lst[i]<0 and (maxneg==0 or lst[i]>maxneg)) maxneg=lst[i];
        if (lst[i]>0 and (minpos==0 or lst[i]<minpos)) minpos=lst[i];
    }
    return {maxneg,minpos};
}
