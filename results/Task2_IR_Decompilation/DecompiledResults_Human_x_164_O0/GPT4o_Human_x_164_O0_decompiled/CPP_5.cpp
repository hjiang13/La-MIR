```cpp
#include <vector>
#include <stdexcept>

void intersperse(std::vector<int>& result, const std::vector<int>& input, int value) {
    result.clear();
    if (input.size() > 0) {
        result.push_back(input[0]);
        for (size_t i = 1; i < input.size(); ++i) {
            result.push_back(value);
            result.push_back(input[i]);
        }
    }
}

int main() {
    std::vector<int> input = {1, 2, 3, 4};
    std::vector<int> result;
    intersperse(result, input, 0);
    return 0;
}
```