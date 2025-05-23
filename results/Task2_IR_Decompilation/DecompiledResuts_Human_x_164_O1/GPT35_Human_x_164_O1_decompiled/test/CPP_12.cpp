```cpp
#include <string>
#include <vector>

std::__cxx11::basic_string longest(std::vector<std::__cxx11::basic_string> v) {
    std::__cxx11::basic_string longest_str;
    if (v.size() == 0) {
        return longest_str;
    }

    longest_str = v[0];

    for (int i = 0; i < v.size(); i++) {
        if (v[i].size() > longest_str.size()) {
            longest_str = v[i];
        }
    }

    return longest_str;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
