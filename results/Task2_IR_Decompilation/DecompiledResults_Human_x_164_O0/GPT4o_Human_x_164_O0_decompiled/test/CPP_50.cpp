#include <string>

void encode_shift(std::string& out, const std::string& in) {
    out.clear();
    for (size_t i = 0; i < in.length(); ++i) {
        char c = in[i];
        c = (c - 'a' + 5) % 26 + 'a';
        out += c;
    }
}

void decode_shift(std::string& out, const std::string& in) {
    out.clear();
    for (size_t i = 0; i < in.length(); ++i) {
        char c = in[i];
        c = (c - 'a' + 21) % 26 + 'a';
        out += c;
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
