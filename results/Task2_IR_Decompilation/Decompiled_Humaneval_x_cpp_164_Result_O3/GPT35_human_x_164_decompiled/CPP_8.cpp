```cpp
#include <vector>

void sum_product(std::vector<int>& result, const std::vector<int>& input) {
    int size = input.size();
    
    if (size == 0) {
        return;
    }
    
    int sum = 0;
    int product = 1;
    
    for (int i = 0; i < size; ++i) {
        sum += input[i];
        product *= input[i];
    }
    
    result.push_back(sum);
    result.push_back(product);
}
```