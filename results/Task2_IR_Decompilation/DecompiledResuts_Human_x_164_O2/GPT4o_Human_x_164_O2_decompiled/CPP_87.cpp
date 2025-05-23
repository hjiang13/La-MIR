```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void get_row(std::vector<std::vector<int>>& result, const std::vector<std::vector<int>>& input, int index) {
    if (index < 0 || index >= static_cast<int>(input.size())) {
        throw std::out_of_range("Index out of range");
    }
    
    result.clear();
    result.resize(input[index].size());
    
    for (size_t i = 0; i < input[index].size(); ++i) {
        result[i].push_back(input[index][i]);
    }
}

int main() {
    // Example usage of get_row
    std::vector<std::vector<int>> input = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<std::vector<int>> result;

    try {
        get_row(result, input, 1); // Retrieves the second row
        for (const auto& row : result) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
```