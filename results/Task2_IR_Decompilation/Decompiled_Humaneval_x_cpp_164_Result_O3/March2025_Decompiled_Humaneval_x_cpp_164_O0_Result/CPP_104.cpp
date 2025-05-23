```cpp
#include <vector>
#include <algorithm>

std::vector<int> unique_digits(const std::vector<int>& input) {
    std::vector<int> result;
    for (int num : input) {
        bool is_unique = true;
        int temp = num;
        if (temp == 0) {
            is_unique = false;
        }
        while (temp > 0 && is_unique) {
            if (temp % 2 == 0) {
                is_unique = false;
            }
            temp /= 10;
        }
        if (is_unique) {
            result.push_back(num);
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}
```