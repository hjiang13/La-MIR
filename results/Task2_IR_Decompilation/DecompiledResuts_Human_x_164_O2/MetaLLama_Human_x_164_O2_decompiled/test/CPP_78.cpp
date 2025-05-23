#include <string.h>

int hex_key(const char* str) {
    const char* key = "2357BD";
    int len = strlen(key);
    int result = 0;

    if (strlen(str) == 0) {
        return 0;
    }

    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (i < len && key[i] == c) {
            result++;
        } else if (i < len && key[i + 1] == c) {
            result++;
        } else if (i < len && key[i + 2] == c) {
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
