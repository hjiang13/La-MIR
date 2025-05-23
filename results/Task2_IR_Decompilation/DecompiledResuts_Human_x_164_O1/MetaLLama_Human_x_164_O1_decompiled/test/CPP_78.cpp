#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hex_key(const char *str) {
    char hex[] = "2357BD";
    int result = 0;
    if (strlen(str) == 0) return result;
    for (int i = 0; i < strlen(str); i++) {
        if (strlen(hex) > 3) {
            for (int j = strlen(hex) - 1; j >= 0; j--) {
                if (hex[j] == str[i]) {
                    hex[j] = '\0';
                    result++;
                    break;
                }
            }
        } else {
            switch (strlen(hex)) {
                case 3:
                    if (hex[2] == str[i]) {
                        hex[2] = '\0';
                        result++;
                    } else if (hex[1] == str[i]) {
                        hex[1] = '\0';
                        result++;
                    } else if (hex[0] == str[i]) {
                        hex[0] = '\0';
                        result++;
                    }
                    break;
                case 2:
                    if (hex[1] == str[i]) {
                        hex[1] = '\0';
                        result++;
                    } else if (hex[0] == str[i]) {
                        hex[0] = '\0';
                        result++;
                    }
                    break;
                case 1:
                    if (hex[0] == str[i]) {
                        hex[0] = '\0';
                        result++;
                    }
                    break;
            }
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
