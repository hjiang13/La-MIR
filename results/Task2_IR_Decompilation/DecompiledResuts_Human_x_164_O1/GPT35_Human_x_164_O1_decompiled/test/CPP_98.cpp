```cpp
#include <string>

int count_upper(std::basic_string<char> *str) {
    std::__cxx11::basic_string<char>::_Alloc_hider* alloc = &str->_M_dataplus._M_p;
    char* data = alloc->_M_p;
    const char* vowels = "AEIOU";
    int count = 0;

    for (size_t i = 0; i < str->_M_dataplus._M_string_length; ++i) {
        char ch = data[i];
        if (strchr(vowels, ch) != nullptr) {
            count++;
        }
    }

    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_upper("aBCdEf")  == 1);
    assert (count_upper("abcdefg") == 0);
    assert (count_upper("dBBE") == 0);
    assert (count_upper("B")  == 0);
    assert (count_upper("U")  == 1);
    assert (count_upper("") == 0);
    assert (count_upper("EEEE") == 2);
}
