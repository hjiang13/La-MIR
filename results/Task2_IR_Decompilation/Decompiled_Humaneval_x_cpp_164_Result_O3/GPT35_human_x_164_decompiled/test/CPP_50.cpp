#include <string>

void encode_shift(std::__cxx11::basic_string<char>& s, const std::__cxx11::basic_string<char>& input) {
    s = "";
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int shift = (c - 92) % 26;
        char encoded_char = static_cast<char>(shift + 97);
        s += encoded_char;
    }
}

void decode_shift(std::__cxx11::basic_string<char>& s, const std::__cxx11::basic_string<char>& input) {
    s = "";
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int shift = (c - 76) % 26;
        char decoded_char = static_cast<char>(shift + 97);
        s += decoded_char;
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
