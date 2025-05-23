/*
This function takes a vector l and returns a vector l' such that
l' is identical to l in the indicies that are not divisible by three, while its values at the indicies that are divisible by three are equal
to the values of the corresponding indicies of l, but sorted.
>>> sort_third({1, 2, 3})
{1, 2, 3}
>>> sort_third({5, 6, 3, 4, 8, 9, 2})
{2, 6, 3, 4, 8, 9, 5}
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sort_third(vector<int> l){

    vector<int> third={};
    int i;
    for (i=0;i*3<l.size();i++)
        third.push_back(l[i*3]);
    
    sort(third.begin(),third.end());

    vector<int> out={};
    for (i=0;i<l.size();i++)
    {
        if (i%3==0) {out.push_back(third[i/3]);}
        else out.push_back(l[i]);
    }
    return out;

}
