```c++
#include <string>

void encode_shift(std::string& result, std::string* input) {
    result.clear();
    int index = 0;
    while (index < input->length()) {
        char currentChar = (*input)[index];
        int shiftedValue = ((currentChar - 'a' + 5) % 26) + 'a';
        result.push_back(static_cast<char>(shiftedValue));
        index++;
    }
}

void decode_shift(std::string& result, std::string* input) {
    result.clear();
    int index = 0;
    while (index < input->length()) {
        char currentChar = (*input)[index];
        int shiftedValue = ((currentChar - 'a' + 21) % 26) + 'a';
        result.push_back(static_cast<char>(shiftedValue));
        index++;
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
