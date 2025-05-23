```c
#include <vector>
#include <iostream>

void intersperse(std::vector<int>& result, const std::vector<int>& input, int value) {
    if (input.empty()) {
        return;
    }

    result.clear();

    for (auto it = input.begin(); it != input.end(); ++it) {
        result.push_back(*it);
        result.push_back(value);
    }

    result.pop_back();
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> result;
    
    intersperse(result, input, 0);

    for (const auto& num : result) {
        std::cout << num << " ";
    }
    
    std::cout << std::endl;

    return 0;
}
```