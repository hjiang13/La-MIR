#include <string>
#include <iterator>

template <typename _CharT, typename _Traits, typename _Alloc>
bool same_chars(std::basic_string<_CharT, _Traits, _Alloc>& str1, std::basic_string<_CharT, _Traits, _Alloc>& str2) {
    int i = 0;
    for (; i < str1.length() && i < str2.length(); ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return i == str1.length() && i == str2.length();
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
