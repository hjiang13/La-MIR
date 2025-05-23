#include <string>
#include <vector>

std::string longest(std::string &result, const std::vector<std::string> &vec) {
    std::string current;
    size_t max_length = 0;

    for (const auto &str : vec) {
        if (str.length() > max_length) {
            max_length = str.length();
            current = str;
        }
    }

    result = current;
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
