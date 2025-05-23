#include <string>
#include <cstring>

bool cycpattern_check(std::string str1, std::string str2) {
    size_t len1 = str1.size();
    size_t len2 = str2.size();
    size_t pos = 0;

    if (len1 == 0 || len2 == 0) {
        return false;
    }

    while (pos < len1) {
        size_t found = str1.find(str2, pos);
        if (found == std::string::npos) {
            return false;
        }
        pos = found + 1;
    }

    return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert  (cycpattern_check("xyzw","xyw") == false );
    assert  (cycpattern_check("yello","ell") == true );
    assert  (cycpattern_check("whattup","ptut") == false );
    assert  (cycpattern_check("efef","fee") == true );
    assert  (cycpattern_check("abab","aabb") == false );
    assert  (cycpattern_check("winemtt","tinem") == true );
}
