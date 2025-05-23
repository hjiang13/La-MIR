```cpp
#include <vector>
#include <algorithm>

void compare(std::vector<int>& result, const std::vector<int>& vec1, const std::vector<int>& vec2) {
    result.clear();
    result.resize(vec1.size());

    for (size_t i = 0; i < vec1.size(); ++i) {
        result[i] = std::abs(vec1[i] - vec2[i]);
    }
}

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {5, 4, 3, 2, 1};
    std::vector<int> result;

    compare(result, vec1, vec2);

    return 0;
}
```