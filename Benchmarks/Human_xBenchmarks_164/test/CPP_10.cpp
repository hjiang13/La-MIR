#include<stdio.h>
#include<string>
using namespace std;
bool is_palindrome(string str){
    //Test if given string is a palindrome 
    string s(str.rbegin(),str.rend());
    return s==str;
}
string make_palindrome(string str){
    /*
    Find the shortest palindrome that begins with a supplied string. 
    Algorithm idea is simple: - Find the longest postfix of supplied string that is a palindrome. 
    - Append to the end of the string reverse of a string prefix that comes before the palindromic suffix.
    >>> make_palindrome("") 
    "" 
    >>> make_palindrome("cat") 
    "catac" 
    >>> make_palindrome("cata") 
    "catac" 
    */

   int i;
   for (i=0;i<str.length();i++)
   {
        string rstr=str.substr(i);
        if (is_palindrome(rstr))
        {
            string nstr;
            nstr=str.substr(0,i);
            string n2str(nstr.rbegin(),nstr.rend());
            return str+n2str;
        }
   }
   string n2str(str.rbegin(),str.rend());
   return str+n2str;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (make_palindrome("") == "");
    assert (make_palindrome("x") == "x");
     assert (make_palindrome("xyz") == "xyzyx");
     assert (make_palindrome("xyx") == "xyx") ;
     assert (make_palindrome("jerry") == "jerryrrej");
}


