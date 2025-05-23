```cpp
#include <vector>
#include <string>
#include <cstring>
#include <cstdint>

void exchange(std::string &result, const std::vector<int> &vec1, const std::vector<int> &vec2) {
    int64_t size1 = vec1.size();
    int64_t size2 = vec2.size();

    if (size1 == 0) {
        result.assign("YES", 3);
        return;
    }

    int count1 = 0;
    for (int i = 0; i < size1; ++i) {
        count1 += (vec1[i] & 1) ^ 1;
    }

    int64_t length = std::max(size1 >> 2, (int64_t)1);
    if (size2 > count1) {
        result.assign(reinterpret_cast<const char *>(&length), sizeof(length));
        result[1] = 2;
        return;
    } else {
        uint16_t value = 20302;
        std::memcpy(&result[0], &value, sizeof(value));
        result.assign("YES", 3);
        result[1] = 2;
    }
}
```