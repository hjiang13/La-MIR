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
    assert (issame(reverse_delete("abcde","ae") , {"bcd","False"}));
    assert (issame(reverse_delete("abcdef", "b") , {"acdef","False"}));
    assert (issame(reverse_delete("abcdedcba","ab") , {"cdedc","True"}));
    assert (issame(reverse_delete("dwik","w") , {"dik","False"}));
    assert (issame(reverse_delete("a","a") , {"","True"}));
    assert (issame(reverse_delete("abcdedcba","") , {"abcdedcba","True"}));
    assert (issame(reverse_delete("abcdedcba","v") , {"abcdedcba","True"}));
    assert (issame(reverse_delete("vabba","v") , {"abba","True"}));
    assert (issame(reverse_delete("mamma", "mia") , {"", "True"}));
}
