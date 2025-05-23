```cpp
#include <vector>
#include <algorithm>

float median(std::vector<float>& vec) {
    float* begin = vec.data();
    float* end = begin + vec.size();

    if (begin == end) {
        return 0.0f; // Handle empty vector
    }

    if (begin + 1 == end) {
        return *begin; // Handle single element
    }

    std::sort(begin, end);
    
    size_t size = end - begin;
    if (size % 2 == 0) {
        return (begin[size / 2 - 1] + begin[size / 2]) / 2.0f;
    } else {
        return begin[size / 2];
    }
}
```