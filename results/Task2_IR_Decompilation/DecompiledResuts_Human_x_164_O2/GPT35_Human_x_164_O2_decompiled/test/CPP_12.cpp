```cpp
#include <string>
#include <vector>

void longest(std::__cxx11::basic_string* s, std::vector* vec) {
    std::__cxx11::basic_string* longest_str = nullptr;
    std::__cxx11::basic_string* current_str = nullptr;
    long longest_length = 0;
    long current_length = 0;
    
    for (int i = 0; i < vec->size(); i++) {
        current_str = vec->at(i);
        current_length = current_str->size();
        
        if (current_length > longest_length) {
            longest_str = current_str;
            longest_length = current_length;
        }
    }
    
    *s = *longest_str;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
