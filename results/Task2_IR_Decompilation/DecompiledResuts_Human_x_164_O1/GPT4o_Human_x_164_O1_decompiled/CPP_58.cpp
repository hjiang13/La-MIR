```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

template<typename T>
void insertion_sort(T* begin, T* end) {
    for (T* i = begin + 1; i < end; ++i) {
        T value = *i;
        T* j = i - 1;
        while (j >= begin && *j > value) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = value;
    }
}

template<typename T>
void introsort(T* begin, T* end, std::size_t depthLimit) {
    while (end - begin > 16) {
        if (depthLimit == 0) {
            std::make_heap(begin, end);
            std::sort_heap(begin, end);
            return;
        }
        --depthLimit;

        T* pivot = begin + (end - begin) / 2;
        std::iter_swap(begin, pivot);
        T* partitionEnd = std::partition(begin + 1, end, [begin](const T& val) {
            return val < *begin;
        });
        std::iter_swap(begin, partitionEnd - 1);
        introsort(begin, partitionEnd - 1, depthLimit);
        begin = partitionEnd;
    }
    insertion_sort(begin, end);
}

extern "C" void common(std::vector<int>& vec1, const std::vector<int>& vec2, const std::vector<int>& vec3) {
    if (vec1.size() == vec2.size() && vec1.size() == vec3.size()) {
        std::vector<int> temp(vec1.size());
        std::memcpy(temp.data(), vec1.data(), vec1.size() * sizeof(int));
        std::memcpy(temp.data() + vec1.size(), vec2.data(), vec2.size() * sizeof(int));
        std::memcpy(temp.data() + vec1.size() + vec2.size(), vec3.data(), vec3.size() * sizeof(int));

        introsort(temp.data(), temp.data() + temp.size(), 2 * std::log(temp.size()));
        std::memcpy(vec1.data(), temp.data(), vec1.size() * sizeof(int));
    } else {
        throw std::length_error("Vectors must be of the same length.");
    }
}
```