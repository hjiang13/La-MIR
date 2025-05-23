```cpp
#include <vector>
#include <algorithm>
#include <iostream>

void unique(std::vector<int>& vec1, std::vector<int>& vec2) {
    std::vector<int> result;
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    for (size_t i = 0; i < size1; ++i) {
        auto it = std::find(vec2.begin(), vec2.end(), vec1[i]);
        if (it != vec2.end()) {
            result.push_back(vec1[i]);
        }
    }

    std::sort(result.begin(), result.end());
    vec1 = result;
}

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {3, 4, 5, 6, 7};

    unique(vec1, vec2);

    for (int value : vec1) {
        std::cout << value << " ";
    }
    return 0;
}
```