/*
Return sorted unique common elements for two vectors.
>>> common({1, 4, 3, 34, 653, 2, 5}, {5, 7, 1, 5, 9, 653, 121})
{1, 5, 653}
>>> common({5, 3, 2, 8}, {3, 2})
{2, 3}

*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> common(vector<int> l1,vector<int> l2){

    vector<int> out={};
    for (int i=0;i<l1.size();i++)
        if (find(out.begin(),out.end(),l1[i])==out.end())
            if (find(l2.begin(),l2.end(),l1[i])!=l2.end())
                out.push_back(l1[i]);
    sort(out.begin(),out.end());
    return out;
}
