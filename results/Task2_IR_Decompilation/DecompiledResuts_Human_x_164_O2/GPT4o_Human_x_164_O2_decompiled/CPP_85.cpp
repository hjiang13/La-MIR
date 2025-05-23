```cpp
#include <vector>

extern "C" int add(std::vector<int>* vec) {
    int* data = vec->data();
    int size = vec->size();
    
    if (size <= 1) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }

    return sum;
}
```