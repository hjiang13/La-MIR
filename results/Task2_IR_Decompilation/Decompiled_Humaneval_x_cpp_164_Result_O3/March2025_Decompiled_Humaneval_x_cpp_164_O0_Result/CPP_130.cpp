```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <iterator>

void tri(std::vector<int>& result, int n) {
    std::vector<int> temp({1, 3});
    if (n == 0) {
        result = std::vector<int>({1});
    } else {
        result = temp;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0) {
                int value = 1 + i / 2;
                temp.push_back(value);
            } else {
                int value1 = temp[i - 1];
                int value2 = temp[i - 2];
                int value = value1 + value2 + 1 + (i + 1) / 2;
                temp.push_back(value);
            }
        }
        result = std::move(temp);
    }
}
```