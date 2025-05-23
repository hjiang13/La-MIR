#include <string>
#include <vector>

void concatenate(std::string& result, std::vector<std::string>& input) {
    std::__cxx11::basic_string<char> temp;
    for (const auto& str : input) {
        temp.append(str);
    }
    result = temp;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (concatenate({}) == "");
     assert (concatenate({"x", "y", "z"}) == "xyz");
    assert (concatenate({"x", "y", "z", "w", "k"}) == "xyzwk");
}
