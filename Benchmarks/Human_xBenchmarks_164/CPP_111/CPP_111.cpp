/*
Given a string representing a space separated lowercase letters, return a map
of the letter with the most repetition and containing the corresponding count.
If several letters have the same occurrence, return all of them.

Example:
histogram("a b c") == {{"a", 1}, {"b", 1}, {"c", 1}}
histogram("a b b a") == {{"a", 2}, {"b", 2}}
histogram("a b c a b") == {{"a", 2}, {"b", 2}}
histogram("b b b b a") == {{"b", 4}}
histogram("") == {}

*/
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
map<char,int> histogram(string test){

    map<char,int> count={},out={};
    map <char,int>::iterator it;
    int max=0;
    for (int i=0;i<test.length();i++)
        if (test[i]!=' ')
        {
            count[test[i]]+=1;
            if (count[test[i]]>max) max=count[test[i]];
        }
    for (it=count.begin();it!=count.end();it++)
    {
        char w1=it->first;
        int w2=it->second;
        if (w2==max) out[w1]=w2;
    }
    return out;
}
