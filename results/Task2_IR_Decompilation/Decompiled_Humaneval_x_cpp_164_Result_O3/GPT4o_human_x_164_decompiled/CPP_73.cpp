```cpp
#include <vector>

extern "C" int smallest_change(std::vector<int>* vec) {
    int* data = vec->data();
    int* end = data + vec->size();
    int count = 0;

    for (int* it = data; it < end; ++it) {
        for (int* it2 = data; it2 < end; ++it2) {
            if (*it != *it2) {
                count++;
            }
        }
    }

    return count;
}
```