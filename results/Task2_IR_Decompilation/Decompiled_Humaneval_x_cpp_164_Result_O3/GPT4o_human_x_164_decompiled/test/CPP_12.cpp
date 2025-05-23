#include <vector>
#include <string>

void longest(std::string &result, const std::vector<std::string> &vec) {
    result.clear();
    size_t max_length = 0;

    for (const auto &s : vec) {
        if (s.length() > max_length) {
            max_length = s.length();
            result = s;
        }
    }
}

int main() {
    std::vector<std::string> strings = {"short", "longer", "longest", "tiny"};
    std::string longest_string;
    longest(longest_string, strings);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
