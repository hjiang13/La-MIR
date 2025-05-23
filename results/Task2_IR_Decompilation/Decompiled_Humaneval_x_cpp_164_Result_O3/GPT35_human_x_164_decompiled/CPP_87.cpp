```cpp
#include <vector>
#include <iostream>

void get_row(std::vector<int>& result, const std::vector<int>& input, int value) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == value) {
            result.push_back(input[i]);
        }
    }
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> result;

    get_row(result, input, 3);

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}
```