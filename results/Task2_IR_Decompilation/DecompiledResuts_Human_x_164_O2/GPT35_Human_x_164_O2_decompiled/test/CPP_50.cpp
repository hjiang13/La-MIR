```cpp
#include <string>

void encode_shift(std::__cxx11::basic_string<char>& s, const std::__cxx11::basic_string<char>& input) {
    s.clear();
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int shift = (c - 92) % 26;
        char encoded = shift + 97;
        s.push_back(encoded);
    }
}

void decode_shift(std::__cxx11::basic_string<char>& s, const std::__cxx11::basic_string<char>& input) {
    s.clear();
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int shift = (c - 76) % 26;
        char decoded = shift + 97;
        s.push_back(decoded);
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
