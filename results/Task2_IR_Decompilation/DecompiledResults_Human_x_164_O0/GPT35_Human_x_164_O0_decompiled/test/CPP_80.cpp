```c++
#include <string>

bool is_happy(std::basic_string<char> *str) {
    bool result;
    int index;
    
    if (str->length() < 3) {
        result = false;
    } else {
        index = 2;
        while (index < str->length()) {
            if ((*str)[index] != (*str)[index - 1]) {
                result = false;
                break;
            }
            index++;
        }
        if (index == str->length()) {
            result = true;
        }
    }
    
    return result;
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
