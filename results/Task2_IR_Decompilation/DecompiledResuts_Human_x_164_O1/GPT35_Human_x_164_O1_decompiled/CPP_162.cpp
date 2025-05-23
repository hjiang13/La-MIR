```c
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
```