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

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(common({1, 4, 3, 34, 653, 2, 5}, {5, 7, 1, 5, 9, 653, 121}) , {1, 5, 653}));
    assert (issame(common({5, 3, 2, 8}, {3, 2}) , {2, 3}));
    assert (issame(common({4, 3, 2, 8}, {3, 2, 4}) , {2, 3, 4}));
    assert (issame(common({4, 3, 2, 8}, {}) , {}));
}
