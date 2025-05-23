```cpp
#include <vector>
#include <stdexcept>
#include <cstring>
#include <cstdlib>

void get_row(std::vector<std::vector<int>>& result, const std::vector<std::vector<int>>& input, int index) {
    if (index < 0 || index >= input.size()) {
        throw std::out_of_range("Index out of range");
    }
    
    size_t rowSize = sizeof(int) * input[index].size();
    result.resize(input[index].size());
    
    std::memset(result.data(), 0, rowSize);
    std::memcpy(result.data(), input[index].data(), rowSize);
}

int main() {
    // Example usage
    std::vector<std::vector<int>> input = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> result;

    try {
        get_row(result, input, 1);
    } catch (const std::out_of_range& e) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
```