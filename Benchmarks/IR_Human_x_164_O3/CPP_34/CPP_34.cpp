/*
Return sorted unique elements in a vector
>>> unique({5, 3, 5, 2, 3, 3, 9, 0, 123})
{0, 2, 3, 5, 9, 123}
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> unique(vector<int> l){

    vector<int> out={};
    for (int i=0;i<l.size();i++)
        if (find(out.begin(),out.end(),l[i])==out.end())
            out.push_back(l[i]);
    sort(out.begin(),out.end());
    return out;
}
