```cpp
#include <vector>
#include <algorithm>

int can_arrange(std::vector<int> &vec) {
    int* data = vec.data();
    int* end = data + vec.size();
    
    if (data == end) return -1;

    int result = -1;
    for (int i = 0; data + i < end; ) {
        int value = data[i];
        if (i < value) {
            result = std::max(result, i);
        }
        i++;
    }

    return result;
}
```