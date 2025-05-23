#include <string>

bool is_happy(const std::string& str) {
    size_t length = str.size();
    if (length < 3) return false;

    char first = str[1];
    for (size_t i = 2; i < length; ++i) {
        if (str[i] != first) {
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
