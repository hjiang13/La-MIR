#include <string>

std::string encode_shift(const std::string &input) {
    std::string result;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        char shifted = ((c - 'a' + 5) % 26) + 'a';
        result += shifted;
    }
    return result;
}

std::string decode_shift(const std::string &input) {
    std::string result;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        char shifted = ((c - 'a' + 21) % 26) + 'a';
        result += shifted;
    }
    return result;
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
