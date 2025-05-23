```cpp
#include <vector>
#include <string>
#include <cstdio>

void odd_count(std::vector<std::string>& output, const std::vector<std::string>& input) {
    size_t count = 0;
    size_t odd_count = 0;
    
    for (const auto& str : input) {
        for (char c : str) {
            if ((c - '0') % 2 != 0) {
                odd_count++;
            }
        }
        if (odd_count > 0) {
            output.push_back(str);
            count++;
        }
    }

    char buffer[57];
    snprintf(buffer, sizeof(buffer), "the number of odd elements in the string i of the input: %zu", count);
    output.push_back(std::string(buffer));
}

int main() {
    std::vector<std::string> input = {"123", "456", "789"};
    std::vector<std::string> output;
    
    odd_count(output, input);

    for (const auto& str : output) {
        printf("%s\n", str.c_str());
    }

    return 0;
}
```