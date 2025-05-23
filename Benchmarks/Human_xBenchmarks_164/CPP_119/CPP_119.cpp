/*
You are given a vector of two strings, both strings consist of open
parentheses '(' or close parentheses ')' only.
Your job is to check if it is possible to concatenate the two strings in
some order, that the resulting string will be good.
A string S is considered to be good if and only if all parentheses in S
are balanced. For example: the string "(())()" is good, while the string
"())" is not.
Return "Yes" if there's a way to make a good string, and return "No" otherwise.

Examples:
match_parens({"()(", ")"}) == "Yes"
match_parens({")", ")"}) == "No"
*/
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
string match_parens(vector<string> lst){

    string l1=lst[0]+lst[1];
    int i,count=0;
    bool can=true;
    for (i=0;i<l1.length();i++)
        {
            if (l1[i]=='(') count+=1;
            if (l1[i]==')') count-=1;
            if (count<0) can=false;
        }
    if (count!=0) return "No";
    if (can==true) return "Yes";
    l1=lst[1]+lst[0];
    can=true;
    for (i=0;i<l1.length();i++)
        {
            if (l1[i]=='(') count+=1;
            if (l1[i]==')') count-=1;
            if (count<0) can=false;
        }
    if (can==true) return "Yes";
    return "No";
}
