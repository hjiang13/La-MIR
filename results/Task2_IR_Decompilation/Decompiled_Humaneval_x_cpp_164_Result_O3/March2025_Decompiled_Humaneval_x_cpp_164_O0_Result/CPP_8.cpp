```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

std::vector<int> sum_product(const std::vector<int>& input) {
    int sum = 0;
    int product = 1;
    for (int value : input) {
        sum += value;
        product *= value;
    }
    return {sum, product};
}
```