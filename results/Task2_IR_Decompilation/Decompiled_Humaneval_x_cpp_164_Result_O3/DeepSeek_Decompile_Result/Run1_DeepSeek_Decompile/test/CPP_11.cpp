#include <string>
#include <algorithm>

using namespace std;

void string_xor(string& result, const string& a, const string& b) {
    result.clear();
    size_t len = min(a.size(), b.size());
    result.reserve(len + 1); // +1 for null terminator
    for (size_t i = 0; i < len; ++i) {
        if (a[i] == b[i]) {
            result += '0';
        } else {
            result += '1';
        }
    }
    result += '\0'; // Ensure null termination
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}
