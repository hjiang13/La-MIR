#include <string>

bool same_chars(std::__cxx11::basic_string<char>* str1, std::__cxx11::basic_string<char>* str2) {
    if (str1->size() == 0) {
        return false;
    }

    if (str1->size() != str2->size()) {
        return false;
    }

    const char* data1 = str1->data();
    const char* data2 = str2->data();

    for (size_t i = 0; i < str1->size(); ++i) {
        if (data1[i] != data2[i]) {
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
