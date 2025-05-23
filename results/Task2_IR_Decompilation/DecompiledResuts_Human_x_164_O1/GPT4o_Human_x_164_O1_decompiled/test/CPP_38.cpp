#include <string>
#include <stdexcept>

void encode_cyclic(std::string &result, const std::string &input) {
    size_t input_size = input.size();
    if (input_size <= 0) {
        result = "";
        return;
    }

    result.resize(input_size);
    for (size_t i = 0; i < input_size; ++i) {
        result[i] = input[i];
    }
}

void decode_cyclic(std::string &result, const std::string &input) {
    size_t input_size = input.size();
    if (input_size <= 0) {
        result = "";
        return;
    }

    result.resize(input_size);
    for (size_t i = 0; i < input_size; ++i) {
        result[i] = input[i];
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

        string encoded_str = encode_cyclic(str);
        assert (decode_cyclic(encoded_str) == str);
    }
}
