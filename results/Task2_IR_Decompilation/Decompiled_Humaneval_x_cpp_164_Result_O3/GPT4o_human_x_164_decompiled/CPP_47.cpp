```cpp
#include <vector>
#include <algorithm>

float median(std::vector<float>& vec) {
    if (vec.size() == 0) return 0.0f;
    if (vec.size() == 1) return vec[0];

    float* begin = vec.data();
    float* end = begin + vec.size();

    std::sort(begin, end);

    size_t size = vec.size();
    if (size % 2 == 0) {
        return (begin[size / 2 - 1] + begin[size / 2]) / 2.0f;
    } else {
        return begin[size / 2];
    }
}

void insertion_sort(float* begin, float* end) {
    for (float* i = begin + 1; i < end; ++i) {
        float key = *i;
        float* j = i - 1;
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
    }
}

void make_heap(float* begin, float* end) {
    std::make_heap(begin, end);
}

int main() {
    std::vector<float> data = {3.0f, 1.0f, 2.0f, 5.0f, 4.0f};
    float med = median(data);
    return 0;
}
```