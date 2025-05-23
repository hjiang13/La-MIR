#include <string>

using namespace std;

void string_xor(string& result, const string& a, const string& b) {
    result.clear();
    
    size_t len_a = a.length();
    size_t len_b = b.length();
    
    size_t min_len = min(len_a, len_b);
    size_t max_len = max(len_a, len_b);
    
    for (size_t i = 0; i < min_len; ++i) {
        char c = a[i] ^ b[i];
        result += c;
    }
    
    if (len_a > len_b) {
        result += a.substr(len_b);
    } else if (len_b > len_a) {
        result += b.substr(len_a);
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}
