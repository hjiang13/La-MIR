#include <string>

using namespace std;

bool is_happy(const string& s) {
    // Check if the string length is less than 3
    if (s.size() < 3) {
        return false;
    }

    // Check the first three characters
    if (s[2] == s[1] || s[1] == s[0]) {
        return false;
    }

    // Check subsequent characters
    for (size_t i = 2; i < s.size(); ++i) {
        if (s[i] == s[i-1]) {
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
