```cpp
#include <vector>
#include <stdexcept>

void f(std::vector<int>& vec, int n) {
    vec.clear();
    for (int i = 1; i <= n; ++i) {
        int value = (i % 2 == 0) ? i : i + 1;
        vec.push_back(value);
    }
}
```