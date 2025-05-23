```cpp
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

void sort_even(std::vector<float>& vec) {
    if (vec.empty()) return;

    std::vector<float> even_elements;
    for (size_t i = 0; i < vec.size(); i += 2) {
        even_elements.push_back(vec[i]);
    }

    std::sort(even_elements.begin(), even_elements.end());

    for (size_t i = 0; i < even_elements.size(); ++i) {
        vec[i * 2] = even_elements[i];
    }
}

int main() {
    std::vector<float> vec = {5.0f, 3.0f, 8.0f, 1.0f, 4.0f, 9.0f};
    sort_even(vec);

    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```