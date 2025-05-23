```cpp
#include <vector>
#include <iostream>

void sum_product(std::vector<int>& result, const std::vector<int>& input) {
    int sum = 0;
    int product = 1;
    
    for (int i = 0; i < input.size(); i++) {
        sum += input[i];
        product *= input[i];
    }
    
    result.push_back(sum);
    result.push_back(product);
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> result;
    
    sum_product(result, input);
    
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    
    return 0;
}
```