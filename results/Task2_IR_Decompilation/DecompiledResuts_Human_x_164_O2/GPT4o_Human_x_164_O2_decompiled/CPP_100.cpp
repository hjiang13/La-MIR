```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void make_a_pile(std::vector<int>& vec, int size) {
    if (size <= 1) {
        return;
    }
    
    vec.resize(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = 0; // Initialize elements to 0
    }

    for (int i = 0; i < size; ++i) {
        vec[i] += 2; // Example operation
    }
}
```