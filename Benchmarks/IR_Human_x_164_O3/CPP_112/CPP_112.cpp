/*
Task
We are given two strings s and c, you have to deleted all the characters in s that are equal to any character in c
then check if the result string is palindrome.
A string is called palindrome if it reads the same backward as forward.
You should return a vector containing the result string and "True"/"False" for the check.
Example
For s = "abcde", c = "ae", the result should be ("bcd","False")
For s = "abcdef", c = "b"  the result should be ("acdef","False")
For s = "abcdedcba", c = "ab", the result should be ("cdedc","True")
*/
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> reverse_delete(string s,string c){

    string n="";
    for (int i=0;i<s.length();i++)
    if (find(c.begin(),c.end(),s[i])==c.end())
        n=n+s[i]; 
    if (n.length()==0) return {n,"True"};
    string w(n.rbegin(),n.rend());
    if (w==n) return {n,"True"};
    return {n,"False"};
}
