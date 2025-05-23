#include <iostream>
#include <string>

using namespace std;

bool is_happy(string str) {
    int level = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            level++;
        } else if (str[i] == ')') {
            level--;
        }
        if (level < 0) {
            return false;
        }
    }
    if (level != 0) {
        return false;
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
