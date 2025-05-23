#include <string>
#include <algorithm>

bool same_chars(const std::string& str1, const std::string& str2) {
    for (size_t i = 0; i < str1.length(); ++i) {
        if (std::find(str2.begin(), str2.end(), str1[i]) == str2.end()) {
            return false;
        }
    }
    for (size_t i = 0; i < str2.length(); ++i) {
        if (std::find(str1.begin(), str1.end(), str2[i]) == str1.end()) {
            return false;
        }
    }
    return true;
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
