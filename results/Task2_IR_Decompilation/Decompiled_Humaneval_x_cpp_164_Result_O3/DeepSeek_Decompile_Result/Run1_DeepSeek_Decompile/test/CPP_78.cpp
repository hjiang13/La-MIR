#include <string>
using namespace std;

int hex_key(const string& s) {
    string hex_string = "2357BD";
    int result = 0;

    if (s.empty()) {
        return 0;
    }

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == hex_string[0] || c == hex_string[1] || 
            c == hex_string[2] || c == hex_string[3] || 
            c == hex_string[4] || c == hex_string[5]) {
            result++;
        }
    }

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (hex_key("AB") == 1      );
    assert (hex_key("1077E") == 2 );
    assert (hex_key("ABED1A33") == 4     );
    assert (hex_key("2020") == 2 );
    assert (hex_key("123456789ABCDEF0") == 6      );
    assert (hex_key("112233445566778899AABBCCDDEEFF00") == 12 );
    assert (hex_key("") == 0);
}
