```cpp
#include <vector>
#include <cstdint>

bool will_it_fly(std::vector<int>& vec, int limit) {
    int* data = vec.data();
    int* end = data + vec.size();
    int64_t size = reinterpret_cast<int64_t>(end) - reinterpret_cast<int64_t>(data);
    size >>= 2;

    if (size == 0) {
        return true;
    }

    int64_t count = 0;
    int32_t sum = 0;

    while (count < size) {
        int32_t current = data[count];
        count++;
        sum += current;
        
        if (count >= limit) {
            break;
        }
    }

    return (sum <= limit);
}
```