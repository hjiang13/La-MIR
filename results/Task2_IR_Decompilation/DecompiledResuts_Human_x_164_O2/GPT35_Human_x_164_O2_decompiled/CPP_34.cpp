```c
#include <vector>
#include <algorithm>

void unique(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();

    if (input.empty()) {
        return;
    }

    result.push_back(input[0]);

    for (size_t i = 1; i < input.size(); ++i) {
        if (input[i] != input[i - 1]) {
            result.push_back(input[i]);
        }
    }
}

int main() {
    std::vector<int> input = {1, 2, 2, 3, 4, 4, 5};
    std::vector<int> result;

    unique(result, input);

    for (const auto& num : result) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}
```