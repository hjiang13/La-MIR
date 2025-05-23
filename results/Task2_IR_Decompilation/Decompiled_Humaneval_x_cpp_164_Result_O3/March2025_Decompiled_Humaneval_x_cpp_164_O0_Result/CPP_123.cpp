```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<int> get_odd_collatz(int n) {
    std::vector<int> result{1};
    while (n != 1) {
        if (n % 2 == 1) {
            result.push_back(n);
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}
```