```cpp
#include <vector>
#include <stdexcept>
#include <algorithm>

std::vector<int> generate_integers(int start, int end) {
    if (end < start) {
        std::swap(start, end);
    }
    std::vector<int> result;
    for (int i = start; i <= end; ++i) {
        if (i < 10 && i % 2 == 0) {
            result.push_back(i);
        }
    }
    return result;
}
```