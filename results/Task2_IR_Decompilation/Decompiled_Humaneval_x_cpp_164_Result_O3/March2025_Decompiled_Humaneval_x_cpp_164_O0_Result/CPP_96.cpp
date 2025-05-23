```cpp
#include <vector>
#include <stdexcept>

void count_up_to(std::vector<int>& vec, int limit) {
    vec.clear();
    for (int i = 2; i < limit; ++i) {
        bool divisible = false;
        for (size_t j = 0; j < vec.size(); ++j) {
            if (i % vec[j] == 0) {
                divisible = true;
                break;
            }
        }
        if (!divisible) {
            vec.push_back(i);
        }
    }
}
```