```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

void sort_third(std::vector<int>& vec1, std::vector<int>& vec2) {
    std::vector<int> temp;

    for (size_t i = 0; i < vec1.size(); i += 3) {
        if (i + 2 < vec1.size()) {
            temp.push_back(vec1[i]);
            temp.push_back(vec1[i + 1]);
            temp.push_back(vec1[i + 2]);
        } else if (i + 1 < vec1.size()) {
            temp.push_back(vec1[i]);
            temp.push_back(vec1[i + 1]);
        } else if (i < vec1.size()) {
            temp.push_back(vec1[i]);
        }
    }

    std::sort(temp.begin(), temp.end());

    for (size_t i = 0; i < temp.size(); ++i) {
        vec2.push_back(temp[i]);
    }
}
```