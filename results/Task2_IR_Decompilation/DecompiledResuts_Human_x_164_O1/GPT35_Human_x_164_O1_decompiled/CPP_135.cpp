```cpp
#include <vector>
#include <algorithm>

int can_arrange(std::vector<int> vec) {
    int* begin = &vec[0];
    int* end = &vec[vec.size() - 1];

    if (begin == end) {
        return -1;
    }

    int size = std::max((end - begin) / 4, 1);

    for (int i = 0; i < size; i++) {
        if (begin[i] > end[i]) {
            return -1;
        }
    }

    return size;
}
```