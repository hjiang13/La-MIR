/*
Concatenate vector of strings into a single string
>>> concatenate({})
""
>>> concatenate({"a", "b", "c"})
"abc"
*/
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
string concatenate(vector<string> strings){

    string out="";
    for (int i=0;i<strings.size();i++)
        out=out+strings[i];
    return out;
}
