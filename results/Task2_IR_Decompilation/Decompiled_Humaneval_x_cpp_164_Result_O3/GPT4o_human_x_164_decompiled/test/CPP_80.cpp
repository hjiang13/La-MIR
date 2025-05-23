#include <string>

bool is_happy(const std::string& str) {
    size_t length = str.size();
    if (length < 3) {
        return false;
    }

    char first_char = str[1];
    char second_char = str[2];
    
    if (second_char == first_char) {
        for (size_t i = 2; i < length; ++i) {
            if (str[i] != str[length - 1 - i + 2]) {
                return false;
            }
        }
        return true;
    }

    for (size_t i = 2; i < length; ++i) {
        if (str[i] == first_char) {
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
