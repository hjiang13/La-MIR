#include <string>
#include <stdexcept>
#include <cstring>

void encode_cyclic(std::string& result, const std::string& input) {
    if (input.size() <= 0) {
        result.clear();
        return;
    }

    size_t size = input.size();
    size_t length = size < 3 ? size : 3;
    result.resize(length);
    
    for (size_t i = 0; i < length; ++i) {
        result[i] = input[i];
    }
    
    result[length] = '\0';
}

void decode_cyclic(std::string& result, const std::string& input) {
    if (input.size() <= 0) {
        result.clear();
        return;
    }

    size_t size = input.size();
    result.resize(size);
    
    for (size_t i = 0; i < size; ++i) {
        result[i] = input[i];
    }

    result[size] = '\0';
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

        string encoded_str = encode_cyclic(str);
        assert (decode_cyclic(encoded_str) == str);
    }
}
