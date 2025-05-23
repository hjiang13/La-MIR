```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void generate_integers(std::vector<int>& vec, int start, int end) {
    if (end < start) {
        end = start;
    }

    int lower = std::min(start, end);
    int upper = std::max(start, end);
    
    vec.resize(upper - lower + 1);
    for (int i = lower; i <= upper; ++i) {
        vec[i - lower] = i;
    }
}
```