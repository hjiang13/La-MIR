```cpp
#include <string>

void encode_shift(std::__cxx11::basic_string<char>& s, std::__cxx11::basic_string<char>& input) {
    s.clear();
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int shift = static_cast<int>(c) - 92;
        int result = (shift % 26) + 97;
        s.push_back(static_cast<char>(result));
    }
}

void decode_shift(std::__cxx11::basic_string<char>& s, std::__cxx11::basic_string<char>& input) {
    s.clear();
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int shift = static_cast<int>(c) - 76;
        int result = (shift % 26) + 97;
        s.push_back(static_cast<char>(result));
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
