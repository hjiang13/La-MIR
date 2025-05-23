```cpp
#include <vector>

int add(std::vector<int> &vec) {
    int *data = vec.data();
    int size = vec.size();
    
    if (size <= 1) return 0;

    long long count = (size >> 2) - 2;
    if (count <= 0) return 0;

    long long result = 0;
    long long mask = 1;

    for (long long i = 0; i < count; ++i) {
        int value = data[i];
        if ((value & 1) == 0) {
            result += value;
        }
        mask = (mask << 1) | 1;
    }
    
    return result;
}
```