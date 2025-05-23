#include <string>

bool is_happy(const std::string& str) {
    if (str.length() < 3) {
        return false;
    }

    for (size_t i = 2; i < str.length(); ++i) {
        if (str[i] == str[i - 1] || str[i] == str[i - 2]) {
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
