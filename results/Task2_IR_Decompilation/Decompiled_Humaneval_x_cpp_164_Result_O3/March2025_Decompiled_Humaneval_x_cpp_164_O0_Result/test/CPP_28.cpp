#include <vector>
#include <string>

extern "C" void concatenate(std::string& result, const std::vector<std::string>& vec) {
    result = "";
    for (const auto& str : vec) {
        result += str;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (concatenate({}) == "");
     assert (concatenate({"x", "y", "z"}) == "xyz");
    assert (concatenate({"x", "y", "z", "w", "k"}) == "xyzwk");
}
