```cpp
#include <vector>

bool will_it_fly(std::vector<int> vec, int size) {
    int* data = vec.data();
    int* end = data + vec.size();
    
    if (data == end) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        if (data[i] != data[vec.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}
```