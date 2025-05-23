```cpp
#include <vector>

void sum_product(std::vector<int>& result, const std::vector<int>& input) {
    int size = input.size();
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[j] += input[i * 4 + j];
        }
    }
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> result(4, 0);
    
    sum_product(result, input);
    
    return 0;
}
```