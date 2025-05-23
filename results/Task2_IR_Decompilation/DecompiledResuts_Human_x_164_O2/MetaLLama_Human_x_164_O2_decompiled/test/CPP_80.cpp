#include <string.h>

int is_happy(const char *str) {
    size_t len = strlen(str);
    if (len < 3) return 0;

    char c1 = str[1];
    char c2 = str[2];
    if (c1 == c2) return 1;

    size_t i = 2;
    bool match = true;
    while (i < len) {
        char c = str[i];
        if (c == str[i - 2]) return 1;
        match = (c == c1);
        i++;
    }

    return !match;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_happy("a") == false );
    assert (is_happy("aa") == false );
    assert (is_happy("abcd") == true );
    assert (is_happy("aabb") == false );
    assert (is_happy("adb") == true );
    assert (is_happy("xyy") == false );
    assert (is_happy("iopaxpoi") == true );
    assert (is_happy("iopaxioi") == false );
}
