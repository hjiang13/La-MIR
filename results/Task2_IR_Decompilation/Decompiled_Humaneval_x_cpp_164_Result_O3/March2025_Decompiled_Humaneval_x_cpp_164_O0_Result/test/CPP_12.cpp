#include <vector>
#include <string>

std::string longest(std::vector<std::string> vec) {
    std::string result;
    for (const auto& str : vec) {
        if (str.length() > result.length()) {
            result = str;
        }
    }
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
