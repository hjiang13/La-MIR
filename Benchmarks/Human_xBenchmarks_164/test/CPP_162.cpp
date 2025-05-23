/*
Given a string 'text", return its md5 hash equivalent string.
If 'text" is an empty string, return None.

>>> string_to_md5("Hello world") == "3e25960a79dbc69b674cd4ec67a72c62"
*/
#include<stdio.h>
#include<string>
#include<openssl/md5.h>
using namespace std;
string string_to_md5(string text){

    unsigned char md[16];
    if (text.length()==0) return "None";
    MD5_CTX c;
    int i;
   MD5_Init(&c);
   MD5_Update(&c, (unsigned char*)text.c_str(), text.length());
    MD5_Final(md, &c);
    string out_str="";
    for (int i=0;i<16;i++)
        {
            char w;
            if (md[i]<160) w=48+md[i]/16;
            else w=87+md[i]/16;
            out_str=out_str+w;
            if (md[i]%16<10) w=48+md[i]%16;
            else w=87+md[i]%16;
            out_str=out_str+w;
        }
    return out_str;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_to_md5("Hello world") == "3e25960a79dbc69b674cd4ec67a72c62");
    assert (string_to_md5("") == "None");
    assert (string_to_md5("A B C") == "0ef78513b0cb8cef12743f5aeb35f888");
    assert (string_to_md5("password") == "5f4dcc3b5aa765d61d8327deb882cf99");
}
