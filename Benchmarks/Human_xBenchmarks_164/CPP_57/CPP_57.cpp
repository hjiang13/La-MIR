/*
Return true is vector elements are monotonically increasing or decreasing.
>>> monotonic({1, 2, 4, 20})
true
>>> monotonic({1, 20, 4, 10})
false
>>> monotonic({4, 1, 0, -10})
true
*/
#include<stdio.h>
#include<vector>
using namespace std;
bool monotonic(vector<float> l){

    int incr,decr;
    incr=0;decr=0;
    for (int i=1;i<l.size();i++)
    {
        if (l[i]>l[i-1]) incr=1;
        if (l[i]<l[i-1]) decr=1;
    }
    if (incr+decr==2) return false;
    return true;
}
