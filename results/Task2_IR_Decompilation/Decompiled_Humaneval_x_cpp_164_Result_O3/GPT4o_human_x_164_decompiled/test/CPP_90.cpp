#include <vector>
#include <algorithm>
#include <iterator>

template<typename Iterator>
void introsort_loop(Iterator first, Iterator last, std::size_t depth_limit) {
    if (depth_limit == 0) {
        std::make_heap(first, last);
        return;
    }
    
    auto size = std::distance(first, last);
    if (size <= 64) {
        std::sort(first, last);
        return;
    }

    auto middle = first + (size / 2);
    std::iter_swap(first, middle);
    std::size_t left_size = std::distance(first, last);

    // Partitioning
    auto pivot = *first;
    auto i = first + 1;
    auto j = last - 1;

    while (i <= j) {
        while (i <= j && *i < pivot) ++i;
        while (i <= j && *j > pivot) --j;
        if (i <= j) {
            std::iter_swap(i++, j--);
        }
    }

    introsort_loop(first, j + 1, depth_limit - 1);
    introsort_loop(i, last, depth_limit - 1);
}

template<typename Iterator>
void sort(Iterator first, Iterator last) {
    std::size_t depth_limit = 2 * std::log(std::distance(first, last));
    introsort_loop(first, last, depth_limit);
}

int next_smallest(std::vector<int>& vec) {
    if (vec.empty()) return -1;
    
    int* first = vec.data();
    int* last = first + vec.size();
    
    sort(first, last);
    
    return *first; // Return the smallest element
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (next_smallest({1, 2, 3, 4, 5}) == 2);
    assert (next_smallest({5, 1, 4, 3, 2}) == 2);
    assert (next_smallest({}) == -1);
    assert (next_smallest({1, 1}) == -1);
    assert (next_smallest({1,1,1,1,0}) == 1);
    assert (next_smallest({-35, 34, 12, -45}) == -35);
}
