```cpp
#include <vector>
#include <stdexcept>

void count_up_to(std::vector<int> &vec, int n) {
    if (n <= 2) return;

    vec.resize(n);
    for (int i = 2; i < n; ++i) {
        vec[i] = i * i;
        if (vec[i] > n) break;
    }
}
```