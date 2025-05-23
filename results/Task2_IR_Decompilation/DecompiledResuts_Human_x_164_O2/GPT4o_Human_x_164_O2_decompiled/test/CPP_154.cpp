#include <string>

bool cycpattern_check(std::string str1, std::string str2) {
    // Initialize variables and allocate memory
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    size_t i = 0, j = 0;

    // Loop through the first string
    while (i < len1) {
        if (j < len2 && str1[i] == str2[j]) {
            j++;
        }
        i++;
        if (j == len2) return true; // Found pattern
    }
    return false; // Pattern not found
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
