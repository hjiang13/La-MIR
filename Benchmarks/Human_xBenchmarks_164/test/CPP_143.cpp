/*
You are given a string representing a sentence,
the sentence contains some words separated by a space,
and you have to return a string that contains the words from the original sentence,
whose lengths are prime numbers,
the order of the words in the new string should be the same as the original one.

Example 1:
    Input: sentence = "This is a test"
    Output: "is"

Example 2:
    Input: sentence = "lets go for swimming"
    Output: "go for"

Constraints:
    * 1 <= len(sentence) <= 100
    * sentence contains only letters
*/
#include<stdio.h>
#include<string>
using namespace std;
string words_in_sentence(string sentence){

    string out="";
    string current="";
    sentence=sentence+' ';

    for (int i=0;i<sentence.size();i++)
    if (sentence[i]!=' ') current=current+sentence[i];
    else
    {
        bool isp=true;
        int l=current.length();
        if (l<2) isp=false;
        for (int j=2;j*j<=l;j++)
            if (l%j==0) isp=false;
        if (isp) out=out+current+' ';
        current="";        
    }
    if (out.length()>0)
        out.pop_back();
    return out;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (words_in_sentence("This is a test") == "is");
    assert (words_in_sentence("lets go for swimming") == "go for");
    assert (words_in_sentence("there is no place available here") == "there is no place");
    assert (words_in_sentence("Hi I am Hussein") == "Hi am Hussein");
    assert (words_in_sentence("go for it") == "go for it");
    assert (words_in_sentence("here") == "");
    assert (words_in_sentence("here is") == "is");
}
