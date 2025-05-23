```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

class MyVector {
public:
    std::vector<int> data;

    void realloc_insert(int size) {
        if (size == 0) {
            data.clear();
            return;
        }
        
        if (size < 2) {
            data.resize(2);
            return;
        }

        int newSize = size + 1;
        if (newSize > data.capacity()) {
            throw std::length_error("vector::_M_realloc_insert");
        }

        data.resize(newSize);
        
        for (int i = 0; i < size; ++i) {
            data[i] = i + 1; // Example initialization
        }
    }
};
```