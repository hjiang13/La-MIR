```cpp
#include <vector>
#include <algorithm>

void remove_duplicates(std::vector<int>& vec) {
    std::vector<int> tmp;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (std::find(tmp.begin(), tmp.end(), vec[i]) == tmp.end()) {
            tmp.push_back(vec[i]);
        }
    }
    vec = std::move(tmp);
}
```