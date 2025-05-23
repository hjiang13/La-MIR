#include <string.h>

int is_happy(const char* str) {
    int len = strlen(str);
    if (len < 3) return 0;

    for (int i = 2; i < len; i++) {
        if (str[i] == str[i-2]) return 0;
    }
    return 1;
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
