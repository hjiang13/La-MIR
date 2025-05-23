/*
Given a string s and a natural number n, you have been tasked to implement 
a function that returns a vector of all words from string s that contain exactly 
n consonants, in order these words appear in the string s.
If the string s is empty then the function should return an empty vector.
Note: you may assume the input string contains only letters and spaces.
Examples:
select_words("Mary had a little lamb", 4) ==> {"little"}
select_words("Mary had a little lamb", 3) ==> {"Mary", "lamb"}
select_words('simple white space", 2) ==> {}
select_words("Hello world", 4) ==> {"world"}
select_words("Uncle sam", 3) ==> {"Uncle"}
*/
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> select_words(string s,int n){

    string vowels="aeiouAEIOU";
    string current="";
    vector<string> out={};
    int numc=0;
    s=s+' ';
    for (int i=0;i<s.length();i++)
        if (s[i]==' ')
        {
            if (numc==n) out.push_back(current);
            current="";
            numc=0;
        }
        else
        {
            current=current+s[i];
            if ((s[i]>=65 and s[i]<=90) or (s[i]>=97 and s[i]<=122))
            if (find(vowels.begin(),vowels.end(),s[i])==vowels.end())
                numc+=1;
        }
    return out;
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
    assert (issame(select_words("Mary had a little lamb", 4) , {"little"}   ));
    assert (issame(select_words("Mary had a little lamb", 3) , {"Mary", "lamb"} ));
    assert (issame(select_words("simple white space", 2) , {}     ));
    assert (issame(select_words("Hello world", 4) , {"world"}  ));
    assert (issame(select_words("Uncle sam", 3) , {"Uncle"}));
    assert (issame(select_words("", 4) , {}));
    assert (issame(select_words("a b c d e f", 1) , {"b", "c", "d", "f"}));
}
