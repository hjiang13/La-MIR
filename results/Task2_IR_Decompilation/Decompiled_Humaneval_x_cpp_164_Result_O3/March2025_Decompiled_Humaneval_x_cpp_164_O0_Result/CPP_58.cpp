```cpp
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

std::vector<int> common(std::vector<int> a, std::vector<int> b) {
    std::vector<int> result;
    for (size_t i = 0; i < a.size(); ++i) {
        if (std::find(result.begin(), result.end(), a[i]) == result.end()) {
            if (std::find(b.begin(), b.end(), a[i]) != b.end()) {
                result.push_back(a[i]);
            }
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}
```