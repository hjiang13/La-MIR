#include <string>
#include <vector>

void concatenate(std::string& result, std::vector<std::string>& strings) {
    std::string temp;
    for (int i = 0; i < strings.size(); i++) {
        temp = strings[i];
        result += temp;
    }
}

int main() {
    std::vector<std::string> strings = {"Hello", "World", "!"};
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
