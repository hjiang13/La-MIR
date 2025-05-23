```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void count_up_to(std::vector<int>& vec, int n) {
    if (n <= 2) {
        return;
    }

    int size = vec.size();
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        vec[i] = i + 1;
    }
}
```