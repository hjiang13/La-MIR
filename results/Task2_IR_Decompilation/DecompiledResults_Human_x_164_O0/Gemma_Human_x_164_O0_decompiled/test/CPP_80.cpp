Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <string.h>

bool is_happy(const std::string& s) {
    if (s.length() < 3) {
        return false;
    }

    int i = 2;
    while (i < s.length()) {
        if (s[i] == s[i - 1] || s[i] == s[i - 2]) {
            return false;
        }
        i++;
    }

    return true;
}
```

Note that I've assumed the `std::string` class is available, as it is used in the IR code. If you want a C-only version without `std::string`, please let me know and I can modify the code accordingly.
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
