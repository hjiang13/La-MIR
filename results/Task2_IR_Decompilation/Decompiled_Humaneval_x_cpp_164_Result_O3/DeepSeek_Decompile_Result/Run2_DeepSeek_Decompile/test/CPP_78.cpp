#include <string>

using namespace std;

int hex_key(const string& s) {
    string hex_string = "2357BD";
    int hex_key = 0;
    size_t length = s.length();

    if (length == 0) {
        return 0;
    }

    for (size_t i = 0; i < length; ++i) {
        char c = s[i];
        if (c == hex_string[0]) {
            hex_key += 0;
        } else if (c == hex_string[1]) {
            hex_key += 1;
        } else if (c == hex_string[2]) {
            hex_key += 2;
        } else if (c == hex_string[3]) {
            hex_key += 3;
        } else if (c == hex_string[4]) {
            hex_key += 4;
        } else if (c == hex_string[5]) {
            hex_key += 5;
        }
    }

    return hex_key;
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
