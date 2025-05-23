#include <string>

void encode_shift(std::string &out, const std::string &in) {
    uint64_t size = 0;
    out = std::string();
    out.resize(in.size());
    size = in.size();
    
    if (size == 0) {
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        out[i] = static_cast<char>((static_cast<uint8_t>(in[i]) + 1) % 256);
    }
}

void decode_shift(std::string &out, const std::string &in) {
    uint64_t size = 0;
    out = std::string();
    out.resize(in.size());
    size = in.size();
    
    if (size == 0) {
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        out[i] = static_cast<char>((static_cast<uint8_t>(in[i]) - 1 + 256) % 256);
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
