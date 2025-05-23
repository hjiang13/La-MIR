```cpp
#include <vector>
#include <string>

void all_prefixes(std::vector<std::string>& vec, const std::string& str) {
    // Clear the vector
    vec.clear();
    
    // Initialize first prefix
    std::string prefix;
    
    for (size_t i = 0; i < str.size(); ++i) {
        prefix += str[i];
        vec.push_back(prefix);
    }
}

int main() {
    std::vector<std::string> prefixes;
    std::string input = "example";
    
    all_prefixes(prefixes, input);
    
    for (const auto& prefix : prefixes) {
        std::cout << prefix << std::endl;
    }
    
    return 0;
}
```