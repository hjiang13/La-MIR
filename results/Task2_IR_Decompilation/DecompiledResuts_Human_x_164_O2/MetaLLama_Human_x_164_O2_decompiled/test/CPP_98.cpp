#include <string.h>

int count_upper(const char* str) {
    const char* s = "AEIOU";
    int count = 0;
    int len = strlen(str);

    if (len == 0) return 0;

    for (int i = 0; i < len / 2; i++) {
        char c = str[i * 2];
        if (c == s[0] || c == s[1] || c == s[2] || c == s[3] || c == s[4]) {
            count++;
        }
    }

    if (len % 2 != 0) {
        char c = str[len - 1];
        if (c == s[0] || c == s[1] || c == s[2] || c == s[3] || c == s[4]) {
            count++;
        }
    }

    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_upper("aBCdEf")  == 1);
    assert (count_upper("abcdefg") == 0);
    assert (count_upper("dBBE") == 0);
    assert (count_upper("B")  == 0);
    assert (count_upper("U")  == 1);
    assert (count_upper("") == 0);
    assert (count_upper("EEEE") == 2);
}
