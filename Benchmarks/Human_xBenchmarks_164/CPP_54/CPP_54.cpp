/*
Check if two words have the same characters.
>>> same_chars("eabcdzzzz", "dddzzzzzzzddeddabc")
true
>>> same_chars("abcd", "dddddddabc")
true
>>> same_chars("dddddddabc", "abcd")
true
>>> same_chars("eabcd", "dddddddabc")
false
>>> same_chars("abcd", "dddddddabce")
false
>>> same_chars("eabcdzzzz", "dddzzzzzzzddddabc")
false
*/
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
bool same_chars(string s0,string s1){

    for (int i=0;i<s0.length();i++)
    if (find(s1.begin(),s1.end(),s0[i])==s1.end())
        return false;
    for (int i=0;i<s1.length();i++)
    if (find(s0.begin(),s0.end(),s1[i])==s0.end())
        return false;
    return true;   
}
