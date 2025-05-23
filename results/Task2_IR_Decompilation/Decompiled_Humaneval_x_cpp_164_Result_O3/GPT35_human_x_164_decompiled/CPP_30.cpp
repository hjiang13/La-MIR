```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void get_positive(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    result.reserve(input.size());

    for (const float& val : input) {
        if (val > 0.0f) {
            result.push_back(val);
        }
    }
}

int main() {
    std::vector<float> input = {1.0f, -2.0f, 3.0f, -4.0f, 5.0f};
    std::vector<float> result;
    
    get_positive(result, input);

    return 0;
}
```