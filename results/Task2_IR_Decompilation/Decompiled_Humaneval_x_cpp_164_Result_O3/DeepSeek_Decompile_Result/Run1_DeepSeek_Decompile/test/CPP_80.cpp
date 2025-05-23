#include <string>

using namespace std;

bool is_happy(const string &s) {
    size_t len = s.length();
    if (len < 3)
        return false;
    char first = s[0];
    if (s[1] == first && s[2] == first)
        return true;
    for (size_t i = 2; i < len; ++i) {
        if (s[i] == s[i-1])
            return true;
    }
    return false;
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
