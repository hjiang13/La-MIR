```c++
#include <vector>
#include <string>
#include <cstring>

void all_prefixes(std::vector<std::string>& output, const std::string* input) {
    output.clear();

    std::string current_prefix;
    for (size_t i = 0; i < input->size(); ++i) {
        current_prefix += input->at(i);
        output.push_back(current_prefix);
    }
}

int main() {
    std::vector<std::string> prefixes;
    std::string input = "example";

    all_prefixes(prefixes, &input);

    for (const auto& prefix : prefixes) {
        std::cout << prefix << std::endl;
    }

    return 0;
}
```