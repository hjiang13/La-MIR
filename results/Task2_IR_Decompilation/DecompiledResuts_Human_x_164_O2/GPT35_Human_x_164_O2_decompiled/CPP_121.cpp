```cpp
#include <vector>
#include <algorithm>

int solutions(std::vector<int> &input) {
    const int *data = input.data();
    int size = input.size();
    
    int total = 0;
    for (int i = 0; i < size; ++i) {
        if (data[i] % 2 == 1) {
            total += data[i];
        }
    }
    
    return total;
}
```