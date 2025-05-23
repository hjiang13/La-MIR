```cpp
#include <iostream>
#include <vector>

void unique_digits(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    size_t input_size = input.size();
    if (input_size == 0) {
        return;
    }

    int prev = input[0] % 10;
    result.push_back(prev);

    for (size_t i = 1; i < input_size; i++) {
        int curr = input[i] % 10;
        if (curr != prev) {
            result.push_back(curr);
            prev = curr;
        }
    }
}

int main() {
    std::vector<int> input = {1, 22, 333, 4444, 55555, 666666, 7777777, 88888888, 999999999};
    std::vector<int> result;
    unique_digits(result, input);

    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```