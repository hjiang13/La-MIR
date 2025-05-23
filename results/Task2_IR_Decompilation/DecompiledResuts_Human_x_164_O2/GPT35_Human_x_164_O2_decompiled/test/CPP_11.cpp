```cpp
#include <string>

void string_xor(std::string& result, const std::string& str1, const std::string& str2) {
    result.clear();
    result.reserve(std::max(str1.size(), str2.size()));

    for (size_t i = 0; i < std::min(str1.size(), str2.size()); ++i) {
        result.push_back(str1[i] ^ str2[i]);
    }
}

int main() {
    std::string str1 = "hello";
    std::string str2 = "world";
    std::string result;

    string_xor(result, str1, str2);

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}
