```cpp
#include <vector>
#include <string>

void concatenate(std::string& result, std::vector<std::string>& strings) {
    std::string temp;
    
    for (std::string& s : strings) {
        temp += s;
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
