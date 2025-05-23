#include <string>
#include <cstring>

struct MD5state_st {
    int32_t arr[16];
    int32_t len;
};

void string_to_md5(std::string& result, const std::string& input) {
    MD5state_st state;
    MD5_Init(&state);

    if (input.size() == 0) {
        result = "";
        return;
    }

    MD5_Update(&state, input.c_str(), input.size());
    MD5_Final(reinterpret_cast<char*>(&result[0]), &state);
}

int main() {
    std::string input = "Hello, World!";
    std::string output;
    
    string_to_md5(output, input);
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_to_md5("Hello world") == "3e25960a79dbc69b674cd4ec67a72c62");
    assert (string_to_md5("") == "None");
    assert (string_to_md5("A B C") == "0ef78513b0cb8cef12743f5aeb35f888");
    assert (string_to_md5("password") == "5f4dcc3b5aa765d61d8327deb882cf99");
}
