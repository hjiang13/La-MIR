```cpp
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

void exchange(std::string &result, const std::vector<int> &vec1, const std::vector<int> &vec2) {
    int *data1 = const_cast<int*>(vec1.data());
    int *data2 = const_cast<int*>(vec2.data());
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();
    size_t minSize = std::min(size1, size2);
    
    for (size_t i = 0; i < minSize; ++i) {
        data1[i] = !data1[i] + data2[i];
    }

    result.resize(3);
    std::memcpy(&result[0], "YES", 3);
}
```