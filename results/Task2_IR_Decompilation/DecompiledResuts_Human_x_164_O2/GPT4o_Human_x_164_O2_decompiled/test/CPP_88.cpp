#include <vector>
#include <cstring>
#include <cstdlib>

void __throw_length_error(const char* msg) {
    throw std::length_error(msg);
}

void* operator new(std::size_t size) {
    void* ptr = std::malloc(size);
    if (!ptr) throw std::bad_alloc();
    return ptr;
}

void operator delete(void* ptr) noexcept {
    std::free(ptr);
}

template<typename Iterator>
void insertion_sort(Iterator first, Iterator last) {
    for (Iterator i = first + 1; i != last; ++i) {
        auto value = *i;
        Iterator j = i - 1;
        while (j >= first && *j > value) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = value;
    }
}

template<typename Iterator>
void introsort(Iterator first, Iterator last) {
    if (last - first <= 16) {
        insertion_sort(first, last);
        return;
    }

    auto mid = first + (last - first) / 2;
    std::nth_element(first, mid, last);
    introsort(first, mid);
    introsort(mid, last);
}

void sort_array(std::vector<int>& vec) {
    if (vec.size() == 0) {
        return;
    }

    introsort(vec.data(), vec.data() + vec.size());
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
    assert (issame(sort_array({}) , {}));
    assert (issame(sort_array({5}) , {5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5}) , {0, 1, 2, 3, 4, 5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5, 6}) , {6, 5, 4, 3, 2, 1, 0}));
    assert (issame(sort_array({2, 1}) , {1, 2}));
    assert (issame(sort_array({15, 42, 87, 32 ,11, 0}) , {0, 11, 15, 32, 42, 87}));
    assert (issame(sort_array({21, 14, 23, 11}) , {23, 21, 14, 11}));
}
