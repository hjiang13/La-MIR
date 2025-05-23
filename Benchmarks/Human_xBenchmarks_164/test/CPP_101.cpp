/*
You will be given a string of words separated by commas or spaces. Your task is
to split the string into words and return a vector of the words.

For example:
words_string("Hi, my name is John") == {"Hi", "my", "name", "is", "John"}
words_string("One, two, three, four, five, six") == {"One", 'two", 'three", "four", "five", 'six"}
*/
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
vector<string> words_string(string s){

    string current="";
    vector<string> out={};
    s=s+' ';
    for (int i=0;i<s.length();i++)
     if (s[i]==' ' or s[i]==',')
     {
        if (current.length()>0)
        {
            out.push_back(current);
            current="";
        }
     }
     else current=current+s[i];
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
    assert (issame(words_string("Hi, my name is John") , {"Hi", "my", "name", "is", "John"}));
    assert (issame(words_string("One, two, three, four, five, six") , {"One", "two", "three", "four", "five", "six"}));
    assert (issame(words_string("Hi, my name") , {"Hi", "my", "name"}));
    assert (issame(words_string("One,, two, three, four, five, six,") , {"One", "two", "three", "four", "five", "six"}));
    assert (issame(words_string("") , {}));
    assert (issame(words_string("ahmed     , gamal") , {"ahmed", "gamal"}));
}
