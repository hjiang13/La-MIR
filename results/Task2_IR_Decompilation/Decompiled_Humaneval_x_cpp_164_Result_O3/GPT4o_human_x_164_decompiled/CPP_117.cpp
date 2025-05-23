```cpp
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void select_words(std::vector<std::string>& vec, const std::string& str, int size) {
    if (size < 0) throw std::length_error("size must be non-negative");
    
    size_t len = str.size();
    if (len > 15) {
        vec.resize(len);
        std::memcpy(vec.data(), str.data(), len);
        vec[len] = '\0';
    } else {
        vec.resize(1);
        vec[0] = str;
    }
}

int main() {
    std::vector<std::string> words;
    std::string input = "example";
    select_words(words, input, input.size());
    
    return 0;
}
```