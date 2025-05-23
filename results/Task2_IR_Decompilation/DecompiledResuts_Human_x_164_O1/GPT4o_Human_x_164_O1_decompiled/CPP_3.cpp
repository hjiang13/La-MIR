```cpp
#include <vector>

extern "C" {
    long long llvm_umax(long long a, long long b);
}

bool below_zero(std::vector<int> &vec) {
    int *data = vec.data();
    int size = vec.size();
    
    if (size == 0) return false;

    long long count = 0;
    long long maxCount = (size + 3) / 4; // Equivalent to shifting right by 2

    for (int i = 0; i < size; i++) {
        int value = data[i];
        if (value < 0) return true;
        count++;
        if (count >= maxCount) break;
    }

    return count < maxCount;
}
```