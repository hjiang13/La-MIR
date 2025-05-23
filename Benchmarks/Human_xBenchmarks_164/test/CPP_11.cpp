/*
Input are two strings a and b consisting only of 1s and 0s.
Perform binary XOR on these inputs and return result also as a string.
>>> string_xor("010", "110")
"100"
*/
#include<stdio.h>
#include<string>
using namespace std;
string string_xor(string a,string b){

    string output="";
    for (int i=0;(i<a.length() and i<b.length());i++)
    {
        if (i<a.length() and i<b.length())
        {
            if (a[i]== b[i]) 
            {
                output+='0';
            }  
            else output+='1';
        }
        else
        {
            if (i>=a.length()) 
            {
            output+=b[i];
            }
            else output+=a[i];
        }
    }
    return output;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}
