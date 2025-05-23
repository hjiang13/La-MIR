#include <string>
#include <cstring>

void encode_shift(std::string& dest, const std::string& src) {
    dest.clear();
    for (size_t i = 0; i < src.size(); ++i) {
        char ch = src[i];
        ch = (ch - 92) % 26 + 'a';
        dest.push_back(ch);
    }
}

void decode_shift(std::string& dest, const std::string& src) {
    dest.clear();
    for (size_t i = 0; i < src.size(); ++i) {
        char ch = src[i];
        ch = (ch - 76) % 26 + 'a';
        dest.push_back(ch);
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    
    for (int i=0;i<100;i++)
    {
        int l=10+rand()%11;
        string str="";
        for (int j=0;j<l;j++)
        {
            char chr=97+rand()%26;
            str+=chr;
        }

        string encoded_str = encode_shift(str);
        assert (decode_shift(encoded_str) == str);
    }
}
