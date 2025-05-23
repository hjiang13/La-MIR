```cpp
#include <vector>
#include <algorithm>

int next_smallest(std::vector<int> &vec) {
    if (vec.empty()) {
        return -1;
    }

    std::sort(vec.begin(), vec.end());

    int smallest = vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] > smallest) {
            return vec[i];
        }
    }

    return -1;
}

int main() {
    std::vector<int> vec = {5, 3, 7, 1, 9, 2};
    int result = next_smallest(vec);
    
    return 0;
}
```