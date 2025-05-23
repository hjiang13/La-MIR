/*
Given a string s, count the number of uppercase vowels in even indices.

For example:
count_upper("aBCdEf") returns 1
count_upper("abcdefg") returns 0
count_upper("dBBE") returns 0
*/
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int count_upper(string s){

    string uvowel="AEIOU";
    int count=0;
    for (int i=0;i*2<s.length();i++)
    if (find(uvowel.begin(),uvowel.end(),s[i*2])!=uvowel.end())
        count+=1;
    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_upper("aBCdEf")  == 1);
    assert (count_upper("abcdefg") == 0);
    assert (count_upper("dBBE") == 0);
    assert (count_upper("B")  == 0);
    assert (count_upper("U")  == 1);
    assert (count_upper("") == 0);
    assert (count_upper("EEEE") == 2);
}
