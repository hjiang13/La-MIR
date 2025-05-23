/*
Given a positive integer, obtain its roman numeral equivalent as a string,
and return it in lowercase.
Restrictions: 1 <= num <= 1000

Examples:
>>> int_to_mini_roman(19) == "xix"
>>> int_to_mini_roman(152) == "clii"
>>> int_to_mini_roman(426) == "cdxxvi"
*/
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
string int_to_mini_romank(int number){

    string current="";
    vector<string> rep={"m","cm","d","cd","c","xc","l","xl","x","ix","v","iv","i"};
    vector<int> num={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    int pos=0;
    while(number>0)
    {
        while (number>=num[pos])
        {
            current=current+rep[pos];
            number-=num[pos];
        }
        if (number>0) pos+=1;
    }
    return current;
}
