```cpp
#include <vector>

void remove_duplicates(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    if (input.empty()) {
        return;
    }

    std::vector<int>::const_iterator it = input.begin();
    result.push_back(*it);

    for (++it; it != input.end(); ++it) {
        if (*it != result.back()) {
            result.push_back(*it);
        }
    }
}
```