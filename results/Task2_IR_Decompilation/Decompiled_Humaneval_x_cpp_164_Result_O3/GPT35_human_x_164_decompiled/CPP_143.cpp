```cpp
#include <string>

void words_in_sentence(std::string& sret, std::string& s) {
    sret = s;
    if (s.size() > 15) {
        sret = s.substr(0, 15);
    }
}

int main() {
    std::string input = "Hello, World!";
    std::string result;
    
    words_in_sentence(result, input);
    
    return 0;
}
```