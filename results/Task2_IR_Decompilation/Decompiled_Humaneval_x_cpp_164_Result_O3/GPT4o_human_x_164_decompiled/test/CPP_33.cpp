#include <vector>
#include <stdexcept>
#include <cstring>
#include <new>

void sort_third(std::vector<int>& vec1, const std::vector<int>& vec2) {
    int* data1 = vec1.data();
    int* data2 = const_cast<int*>(vec2.data());
    
    if (data1 == data2) return;

    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    if (data1 == nullptr) {
        vec1 = vec2;
        return;
    }

    if (size1 == 0 && size2 == 0) return;

    if (size1 > size2) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    size_t newSize = size1 + size2;
    if (newSize > SIZE_MAX / sizeof(int)) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    std::vector<int> result(newSize);
    std::memcpy(result.data(), data1, size1 * sizeof(int));
    std::memcpy(result.data() + size1, data2, size2 * sizeof(int));

    vec1 = std::move(result);
}

void insertion_sort(int* begin, int* end) {
    for (int* i = begin + 1; i < end; ++i) {
        int key = *i;
        int* j = i - 1;
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

void make_heap(int* begin, int* end) {
    if (end - begin <= 1) return;

    for (int* it = begin + 1; it < end; ++it) {
        std::push_heap(begin, it + 1);
    }
}

void sort(std::vector<int>& vec) {
    if (vec.size() < 64) {
        insertion_sort(vec.data(), vec.data() + vec.size());
    } else {
        make_heap(vec.data(), vec.data() + vec.size());
        std::sort_heap(vec.data(), vec.data() + vec.size());
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
    assert (issame(sort_third({1, 2, 3}) , sort_third({1, 2, 3})));
    assert (issame(sort_third({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10}) , sort_third({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10})));
    assert (issame(sort_third({5, 8, -12, 4, 23, 2, 3, 11, 12, -10}) , sort_third({5, 8, -12, 4, 23, 2, 3, 11, 12, -10})));
    assert (issame(sort_third({5, 6, 3, 4, 8, 9, 2}) , {2, 6, 3, 4, 8, 9, 5}));
    assert (issame(sort_third({5, 8, 3, 4, 6, 9, 2}) , {2, 8, 3, 4, 6, 9, 5}));
    assert (issame(sort_third({5, 6, 9, 4, 8, 3, 2}) , {2, 6, 9, 4, 8, 3, 5}));
    assert (issame(sort_third({5, 6, 3, 4, 8, 9, 2, 1}) , {2, 6, 3, 4, 8, 9, 5, 1}));
}
