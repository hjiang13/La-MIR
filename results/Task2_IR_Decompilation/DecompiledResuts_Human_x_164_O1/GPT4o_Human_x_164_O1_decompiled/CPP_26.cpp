```cpp
#include <vector>
#include <algorithm>
#include <iostream>

void remove_duplicates(std::vector<int> &vec) {
    if (vec.empty()) return;

    std::vector<int> unique;
    std::sort(vec.begin(), vec.end());
    unique.push_back(vec[0]);

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] != vec[i - 1]) {
            unique.push_back(vec[i]);
        }
    }

    vec = std::move(unique);
}

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 5};
    remove_duplicates(vec);

    for (int num : vec) {
        std::cout << num << " ";
    }

    return 0;
}
```