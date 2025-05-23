#include <string>

std::string string_xor(const std::string &a, const std::string &b) {
    std::string result;
    size_t min_len = std::min(a.size(), b.size());
    
    for (size_t i = 0; i < min_len; ++i) {
        if (a[i] == b[i]) {
            result += '0';
        } else {
            result += '1';
        }
    }
    
    if (a.size() < b.size()) {
        result.append(b.size() - a.size(), '1');
    } else if (b.size() < a.size()) {
        result.append(a.size() - b.size(), '1');
    }
    
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}
