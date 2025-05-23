#include <string.h>

void string_xor(std::string* result, const std::string& str1, const std::string& str2) {
    result->clear();
    if (str1.size() == 0) return;

    size_t len1 = str1.size();
    size_t len2 = str2.size();
    size_t len = len1 < len2 ? len1 : len2;

    result->reserve(len + 1);

    for (size_t i = 0; i < len; ++i) {
        char c1 = str1[i];
        char c2 = str2[i];
        char c = c1 == c2 ? 48 : 49;
        result->push_back(c);
    }

    result->push_back('\0');
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}
