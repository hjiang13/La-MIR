/*
Create a function which takes a string representing a file's name, and returns
"Yes" if the the file's name is valid, and returns "No" otherwise.
A file's name is considered to be valid if and only if all the following conditions 
are met:
- There should not be more than three digits ('0'-'9') in the file's name.
- The file's name contains exactly one dot "."
- The substring before the dot should not be empty, and it starts with a letter from 
the latin alphapet ('a'-'z' and 'A'-'Z').
- The substring after the dot should be one of these: {'txt", "exe", "dll"}
Examples:
file_name_check("example.txt") => "Yes"
file_name_check("1example.dll")  => "No" // (the name should start with a latin alphapet letter)
*/
#include<stdio.h>
#include<string>
using namespace std;
string file_name_check(string file_name){

    int numdigit=0,numdot=0;
    if (file_name.length()<5) return "No";
    char w=file_name[0];
    if (w<65 or (w>90 and w<97) or w>122) return "No";
    string last=file_name.substr(file_name.length()-4,4);
    if (last!=".txt" and last!=".exe" and last!=".dll") return "No";
    for (int i=0;i<file_name.length();i++)
    {
        if (file_name[i]>=48 and file_name[i]<=57) numdigit+=1;
        if (file_name[i]=='.') numdot+=1;
    }
    if (numdigit>3 or numdot!=1) return "No";
    return "Yes"; 
}
