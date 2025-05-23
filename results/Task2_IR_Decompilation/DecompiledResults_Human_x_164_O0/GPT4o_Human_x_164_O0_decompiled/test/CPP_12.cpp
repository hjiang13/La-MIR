#include <vector>
#include <string>

std::string longest(std::string &result, const std::vector<std::string> &vec) {
    size_t maxIndex = 0;
    size_t maxLength = result.length();

    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i].length() > maxLength) {
            maxLength = vec[i].length();
            maxIndex = i;
        }
    }

    result = vec[maxIndex];
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
