```cpp
#include <vector>
#include <iostream>

void get_row(std::vector<int>& result, const std::vector<int>& input, int index) {
    result.clear();
    if (input.empty()) {
        return;
    }

    const std::vector<int>& vec = input;
    if (index >= vec.size()) {
        return;
    }

    result.push_back(vec[index]);
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> result;

    get_row(result, input, 2);

    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```