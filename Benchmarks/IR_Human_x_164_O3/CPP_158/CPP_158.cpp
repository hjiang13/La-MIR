/*
Write a function that accepts a vector of strings.
The vector contains different words. Return the word with maximum number
of unique characters. If multiple strings have maximum number of unique
characters, return the one which comes first in lexicographical order.

find_max({"name", "of", 'string"}) == 'string"
find_max({"name", "enam", "game"}) == "enam"
find_max({"aaaaaaa", "bb" ,"cc"}) == "aaaaaaa"
*/
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string find_max(vector<string> words){

    string max="";
    int maxu=0;
    for (int i=0;i<words.size();i++)
    {
        string unique="";
        for (int j=0;j<words[i].length();j++)
            if (find(unique.begin(),unique.end(),words[i][j])==unique.end())
                unique=unique+words[i][j];
        if (unique.length()>maxu or (unique.length()==maxu and words[i]<max))
        {
            max=words[i];
            maxu=unique.length();
        }
    }
    return max;
}
