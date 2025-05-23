/*
Given a string of words, return a vector of words split on whitespace, if no whitespaces exists in the text you
should split on commas ',' if no commas exists you should return a vector with one element, the number of lower-case letters with odd order in the
alphabet, ord("a") = 0, ord("b") = 1, ... ord("z") = 25
Examples
split_words("Hello world!") ➞ {"Hello", "world!"}
split_words("Hello,world!") ➞ {"Hello", "world!"}
split_words("abcdef") == {"3"} 
*/
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> split_words(string txt){

    int i;
    string current="";
    vector<string> out={};
    if (find(txt.begin(),txt.end(),' ')!=txt.end())
    {
        txt=txt+' ';
        for (i=0;i<txt.length();i++)
            if (txt[i]==' ') 
            {
                if (current.length()>0)out.push_back(current); 
                current="";
            }
            else current=current+txt[i];
        return out;
    }
    if (find(txt.begin(),txt.end(),',')!=txt.end())
    {
        txt=txt+',';
        for (i=0;i<txt.length();i++)
            if (txt[i]==',') 
            {
                if (current.length()>0)out.push_back(current); 
                current="";
            }
            else current=current+txt[i];
        return out;
    }
    int num=0;
    for (i=0;i<txt.length();i++)
        if (txt[i]>=97 and txt[i]<=122 and txt[i]%2==0)
            num+=1;
    return {to_string(num)};
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<string> a,vector<string>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(split_words("Hello world!") , {"Hello","world!"}));
    assert (issame(split_words("Hello,world!") , {"Hello","world!"}));
    assert (issame(split_words("Hello world,!") , {"Hello","world,!"}));
    assert (issame(split_words("Hello,Hello,world !") , {"Hello,Hello,world","!"}));
    assert (issame(split_words("abcdef") , {"3"}));
    assert (issame(split_words("aaabb") , {"2"}));
    assert (issame(split_words("aaaBb") , {"1"}));
    assert (issame(split_words("") ,{"0"}));
}
