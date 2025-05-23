```c++
#include <vector>
#include <string>

void all_prefixes(std::vector<std::string>& result, std::string* input) {
    result.clear();
    std::string current_prefix;
    
    for (size_t i = 0; i < input->size(); ++i) {
        current_prefix += (*input)[i];
        result.push_back(current_prefix);
    }
}

int main() {
    std::vector<std::string> prefixes;
    std::string input = "hello";
    
    all_prefixes(prefixes, &input);
    
    for (const auto& prefix : prefixes) {
        std::cout << prefix << std::endl;
    }
    
    return 0;
}
```