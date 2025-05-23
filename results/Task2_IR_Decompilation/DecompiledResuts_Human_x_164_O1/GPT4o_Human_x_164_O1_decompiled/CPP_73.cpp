```cpp
#include <vector>

int smallest_change(std::vector<int> const& vec) {
    int* data = vec.data();
    int* end = data + vec.size();
    int count = 0;

    if (data == end) {
        return count;
    }

    for (int* it = data; it < end - 1; ++it) {
        if (*it != *(it + 1)) {
            count++;
        }
    }

    return count;
}
```