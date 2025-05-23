```cpp
#include <vector>
#include <cstdint>

int64_t umax(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

int can_arrange(std::vector<int> &vec) {
    int32_t *data = vec.data();
    int32_t *end = data + vec.size();
    
    if (data == end) {
        return -1;
    }

    int64_t idx = 0;
    int32_t result = -1;

    while (true) {
        if (idx >= *end) {
            result = idx;
            break;
        }
        result = idx < *data ? idx : result;
        idx++;
        
        if (idx == umax(idx >> 2, 1)) {
            break;
        }
    }

    return result;
}
```