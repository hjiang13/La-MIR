```cpp
#include <vector>

void pluck(std::vector<int>& result, std::vector<int>& input) {
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] & 1 == 0) {
            if (result.size() == 0 || input[i] < result.back()) {
                result.push_back(input[i]);
            }
        }
    }
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> result;
    
    pluck(result, input);
    
    return 0;
}
```