```cpp
#include <vector>
#include <algorithm>

void sort_third(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    result.reserve(input.size());

    for (size_t i = 0; i < input.size(); ++i) {
        size_t index = i * 3;
        if (index < input.size()) {
            result.push_back(input[index]);
        }
    }

    std::sort(result.begin(), result.end());
}

int main() {
    std::vector<int> input = {5, 1, 7, 3, 9, 2, 6};
    std::vector<int> result;

    sort_third(result, input);

    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```