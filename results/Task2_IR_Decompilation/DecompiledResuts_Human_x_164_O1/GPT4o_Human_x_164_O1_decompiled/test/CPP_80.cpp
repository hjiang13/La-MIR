#include <string>

bool is_happy(const std::string& str) {
    size_t length = str.size();
    if (length < 3) {
        return false;
    }

    for (size_t i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
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
