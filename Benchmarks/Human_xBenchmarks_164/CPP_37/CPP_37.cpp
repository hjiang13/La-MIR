/*
This function takes a vector l and returns a vector l' such that
l' is identical to l in the odd indicies, while its values at the even indicies are equal
to the values of the even indicies of l, but sorted.
>>> sort_even({1, 2, 3})
{1, 2, 3}
>>> sort_even({5, 6, 3, 4})
{3, 6, 5, 4}
*/
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<float> sort_even(vector<float> l){

    vector<float> out={};
    vector<float> even={};
    for (int i=0;i*2<l.size();i++)
        even.push_back(l[i*2]);
    sort(even.begin(),even.end());
    for (int i=0;i<l.size();i++)
    {
        if (i%2==0) out.push_back(even[i/2]);
        if (i%2==1) out.push_back(l[i]);
    }
    return out;
}
