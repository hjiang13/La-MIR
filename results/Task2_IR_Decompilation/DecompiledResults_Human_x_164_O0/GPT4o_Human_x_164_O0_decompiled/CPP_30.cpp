```cpp
#include <vector>
#include <stdexcept>

void get_positive(std::vector<float>& v, const std::vector<float>& input) {
    v.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] > 0.0f) {
            v.push_back(input[i]);
        }
    }
}
```