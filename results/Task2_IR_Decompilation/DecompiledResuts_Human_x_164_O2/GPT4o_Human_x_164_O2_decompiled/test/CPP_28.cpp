#include <string>
#include <vector>
#include <cstring>

void concatenate(std::string &result, const std::vector<std::string> &strings) {
    result.clear();
    for (const auto &str : strings) {
        result += str;
    }
}

int main() {
    std::vector<std::string> strings = {"Hello, ", "world!", " This is a test."};
    std::string result;
    concatenate(result, strings);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (concatenate({}) == "");
     assert (concatenate({"x", "y", "z"}) == "xyz");
    assert (concatenate({"x", "y", "z", "w", "k"}) == "xyzwk");
}
