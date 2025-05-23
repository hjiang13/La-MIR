```cpp
#include <vector>

int max_fill(std::vector<int> &vec, int size) {
    int count = 0;
    int index = 0;
    int total = 0;

    while (index < vec.size()) {
        total += vec[index];
        count++;
        index++;
    }

    if (count > 0) {
        return total / count + 1;
    }
    return 0;
}
```