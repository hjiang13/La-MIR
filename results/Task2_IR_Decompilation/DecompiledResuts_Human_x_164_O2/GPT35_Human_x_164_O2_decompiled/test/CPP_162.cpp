```c++
#include <string>
#include <cstring>

struct MD5state_st {
    int32_t data[8];
};

void string_to_md5(std::string& output, const std::string& input) {
    MD5state_st state;
    MD5_Init(&state);
    MD5_Update(&state, input.c_str(), input.size());
    
    unsigned char result[16];
    MD5_Final(result, &state);
    
    output.clear();
    output.resize(32);
    
    for (int i = 0; i < 16; ++i) {
        sprintf(&output[i * 2], "%02x", result[i]);
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_to_md5("Hello world") == "3e25960a79dbc69b674cd4ec67a72c62");
    assert (string_to_md5("") == "None");
    assert (string_to_md5("A B C") == "0ef78513b0cb8cef12743f5aeb35f888");
    assert (string_to_md5("password") == "5f4dcc3b5aa765d61d8327deb882cf99");
}
