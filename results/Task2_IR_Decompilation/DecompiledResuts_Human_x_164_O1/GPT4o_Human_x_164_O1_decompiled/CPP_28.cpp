```cpp
#include <iostream>
#include <string>
#include <vector>

void concatenate(std::string& result, const std::vector<std::string>& strings) {
    result.clear();
    for (const auto& str : strings) {
        result += str;
    }
}

int main() {
    std::vector<std::string> strings = {"Hello, ", "World!", " Welcome to LLVM."};
    std::string result;

    concatenate(result, strings);
    std::cout << result << std::endl;

    return 0;
}
```