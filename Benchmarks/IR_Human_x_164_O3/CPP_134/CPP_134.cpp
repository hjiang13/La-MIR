/*
Create a function that returns true if the last character
of a given string is an alphabetical character and is not
a part of a word, and false otherwise.
Note: "word" is a group of characters separated by space.

Examples:
check_if_last_char_is_a_letter("apple pie") ➞ false
check_if_last_char_is_a_le/home/anonymous/LLMs-in-IR/Human_xBenchmarks_164/CPP_139tter("apple pi e") ➞ true
check_if_last_char_is_a_letter("apple pi e ") ➞ false
check_if_last_char_is_a_letter("") ➞ false 
*/
#include<stdio.h>
#include<string>
using namespace std;
bool check_if_last_char_is_a_letter(string txt){

    if (txt.length()==0) return false;
    char chr=txt[txt.length()-1];
    if (chr<65 or (chr>90 and chr<97) or chr>122) return false;
    if (txt.length()==1) return true;
    chr=txt[txt.length()-2];
    if ((chr>=65 and chr<=90) or (chr>=97 and chr<=122)) return false;
    return true;
}
