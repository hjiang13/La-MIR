#include <string>

void encode_cyclic(std::string &out, const std::string &in) {
    size_t len = in.length();
    int iterations = (len + 2) / 3;
    out.clear();

    for (int i = 0; i < iterations; ++i) {
        size_t start = i * 3;
        if (start < len) {
            out += in.substr(start, 3);
        }
    }
}

void decode_cyclic(std::string &out, const std::string &in) {
    size_t len = in.length();
    int iterations = (len + 2) / 3;
    out.clear();

    for (int i = 0; i < iterations; ++i) {
        size_t start = i * 3;
        if (start < len) {
            out += in.substr(start, 3);
        }
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
