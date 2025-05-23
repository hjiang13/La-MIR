/*
Write a function vowels_count which takes a string representing a word as input and returns the number of vowels in the string. Vowels in this case are 'a', 'e', 'i', 'o', 'u'. 
Here, 'y' is also a vowel, but only when it is at the end of the given word.
Example: 
>>> vowels_count("abcde") 
2 
>>> vowels_count("ACEDY") 
3
*/
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int vowels_count(string s){

    string vowels="aeiouAEIOU";
    int count=0;
    for (int i=0;i<s.length();i++)
    if (find(vowels.begin(),vowels.end(),s[i])!=vowels.end())
        count+=1;
    if (s[s.length()-1]=='y' or s[s.length()-1]=='Y') count+=1;
    return count;
}
