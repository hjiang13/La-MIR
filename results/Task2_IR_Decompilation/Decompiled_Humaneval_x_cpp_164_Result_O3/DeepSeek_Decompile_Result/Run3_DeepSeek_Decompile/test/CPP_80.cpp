#include <string>

using namespace std;

bool is_happy(const string& s) {
    if (s.length() < 3) {
        return false;
    }
    for (int i = 0; i <= s.length() - 3; ++i) {
        if (s[i] == s[i+1] && s[i] == s[i+2]) {
            return true;
        }
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
