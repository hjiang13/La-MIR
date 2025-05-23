```c++
#include <string>

int count_upper(std::__cxx11::basic_string<char> *str) {
    std::__cxx11::basic_string<char>::_Alloc_hider *alloc = &str->__data;
    int count = 0;

    for (size_t i = 0; i < str->__size; ++i) {
        char c = alloc->__lx.ptr[i];
        if (c >= 'A' && c <= 'Z') {
            ++count;
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
