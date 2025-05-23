```cpp
#include <vector>

void generate_integers(std::vector<int>& vec, int start, int end) {
    for (int i = start; i < end; ++i) {
        if (i % 2 == 0) {
            vec.push_back(i);
        }
    }
}
```