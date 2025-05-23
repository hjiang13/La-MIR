#include <string>

bool is_happy(std::basic_string<char> *str) {
    size_t size = str->size();
    if (size < 3) {
        return true;
    }

    char *data = &(*str)[0];
    char prev = data[1];
    char curr = data[2];

    if (prev == curr) {
        return false;
    }

    for (size_t i = 3; i < size; i++) {
        char next = data[i];
        if (next == curr) {
            return false;
        }
        prev = curr;
        curr = next;
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
