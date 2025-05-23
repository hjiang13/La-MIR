```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void sort_even(std::vector<float> &vec1, std::vector<float> &vec2) {
    std::vector<float> temp;
    temp.reserve(vec1.size());
    for (size_t i = 0; i < vec1.size(); i += 2) {
        if (i < vec2.size()) {
            temp.push_back(vec2[i]);
        }
    }
    std::sort(temp.begin(), temp.end());
    for (size_t i = 0; i < temp.size(); ++i) {
        if (i < vec1.size()) {
            vec1[i] = temp[i];
        }
    }
}

int main() {
    std::vector<float> vec1 = {5.0, 3.0, 2.0, 4.0, 1.0};
    std::vector<float> vec2 = {10.0, 9.0, 8.0, 7.0, 6.0};

    sort_even(vec1, vec2);

    for (const auto &val : vec1) {
        std::cout << val << " ";
    }
    return 0;
}
```