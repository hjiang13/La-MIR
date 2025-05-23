/*
Given a vector of numbers, return whether or not they are sorted
in ascending order. If vector has more than 1 duplicate of the same
number, return false. Assume no negative numbers and only integers.

Examples
is_sorted({5}) ➞ true
is_sorted({1, 2, 3, 4, 5}) ➞ true
is_sorted({1, 3, 2, 4, 5}) ➞ false
is_sorted({1, 2, 3, 4, 5, 6}) ➞ true
is_sorted({1, 2, 3, 4, 5, 6, 7}) ➞ true
is_sorted({1, 3, 2, 4, 5, 6, 7}) ➞ false
is_sorted({1, 2, 2, 3, 3, 4}) ➞ true
is_sorted({1, 2, 2, 2, 3, 4}) ➞ false
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool is_sorted(vector<int> lst){

    for (int i=1;i<lst.size();i++)
    {
        if (lst[i]<lst[i-1]) return false;
        if (i>=2 and lst[i]==lst[i-1] and lst[i]==lst[i-2]) return false;
    }
    return true;
}
