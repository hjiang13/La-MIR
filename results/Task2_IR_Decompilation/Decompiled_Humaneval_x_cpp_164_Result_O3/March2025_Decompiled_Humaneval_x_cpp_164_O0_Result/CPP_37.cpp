```cpp
#include <vector>
#include <algorithm>

std::vector<float> sort_even(const std::vector<float>& input) {
    std::vector<float> even_elements;
    std::vector<float> result;

    for (size_t i = 0; i < input.size(); i += 2) {
        even_elements.push_back(input[i]);
    }

    std::sort(even_elements.begin(), even_elements.end());

    for (size_t i = 0; i < input.size(); ++i) {
        if (i % 2 == 0) {
            result.push_back(even_elements[i / 2]);
        } else {
            result.push_back(input[i]);
        }
    }

    return result;
}
```