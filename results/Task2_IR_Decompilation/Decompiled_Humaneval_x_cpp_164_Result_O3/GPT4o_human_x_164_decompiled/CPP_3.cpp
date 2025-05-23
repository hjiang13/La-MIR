```cpp
#include <vector>

extern "C" bool below_zero(std::vector<int>* vec) {
    int* data = vec->_Myptr();
    int size = vec->size();
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (data[i] < 0) {
            count++;
        }
    }

    return count > 0;
}
```