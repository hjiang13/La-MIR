/*
You will be given a number in decimal form and your task is to convert it to
binary format. The function should return a string, with each character representing a binary
number. Each character in the string will be '0' or '1'.

There will be an extra couple of characters "db" at the beginning and at the end of the string.
The extra characters are there to help with the format.

Examples:
decimal_to_binary(15)   // returns "db1111db"
decimal_to_binary(32)   // returns "db100000db"
*/
#include<stdio.h>
#include<string>
using namespace std;
string decimal_to_binary(int decimal){

    string out="";
    if (decimal==0) return "db0db";
    while (decimal>0)
    {
        out=to_string(decimal%2)+out;
        decimal=decimal/2;
    }
    out="db"+out+"db";
    return out;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (decimal_to_binary(0) == "db0db");
    assert (decimal_to_binary(32) == "db100000db");
    assert (decimal_to_binary(103) == "db1100111db");
    assert (decimal_to_binary(15) == "db1111db");

}
