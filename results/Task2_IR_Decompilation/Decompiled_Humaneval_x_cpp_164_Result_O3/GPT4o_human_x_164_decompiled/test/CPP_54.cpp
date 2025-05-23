#include <string>

bool same_chars(std::string str1, std::string str2) {
    if (str1.length() == 0) {
        return str2.length() == 0;
    }

    size_t length1 = str1.length();
    size_t length2 = str2.length();
    
    if (length1 > 3) {
        for (size_t i = 0; i < length1; ++i) {
            if (i >= length2 || str1[i] != str2[i]) {
                return false;
            }
        }
    } else {
        for (size_t i = 0; i < length1; ++i) {
            if (i >= length2 || str1[i] != str2[i]) {
                return false;
            }
        }
    }

    return length1 == length2;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (same_chars("eabcdzzzz", "dddzzzzzzzddeddabc") == true);
    assert (same_chars("abcd", "dddddddabc") == true);
    assert (same_chars("dddddddabc", "abcd") == true);
    assert (same_chars("eabcd", "dddddddabc") == false);
    assert (same_chars("abcd", "dddddddabcf") == false);
    assert (same_chars("eabcdzzzz", "dddzzzzzzzddddabc") == false);
    assert (same_chars("aabb", "aaccc") == false);
}
