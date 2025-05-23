#include <string>

void string_xor(std::string &result, const std::string &str1, const std::string &str2) {
    result.clear();
    size_t len1 = str1.size();
    size_t len2 = str2.size();
    size_t min_len = std::min(len1, len2);
    
    for (size_t i = 0; i < min_len; ++i) {
        result.push_back(str1[i] ^ str2[i]);
    }
    
    if (len1 > min_len) {
        result.append(str1.substr(min_len));
    } else if (len2 > min_len) {
        result.append(str2.substr(min_len));
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}
