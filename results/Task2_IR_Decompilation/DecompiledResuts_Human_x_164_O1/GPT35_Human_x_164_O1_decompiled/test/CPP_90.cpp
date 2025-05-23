```cpp
#include <vector>
#include <algorithm>

int next_smallest(std::vector<int> &vec) {
    int* begin = &vec[0];
    int* end = &vec[vec.size() - 1];

    if (begin == end) {
        return -1;
    }

    int diff = end - begin;
    int shift = diff >> 2;
    int count = __builtin_clz(shift) << 1;
    int threshold = count ^ 126;

    std::__introsort_loop(std::__normal_iterator<int*, std::vector<int>>(begin), 
                          std::__normal_iterator<int*, std::vector<int>>(end), 
                          threshold);

    std::__final_insertion_sort(std::__normal_iterator<int*, std::vector<int>>(begin), 
                                std::__normal_iterator<int*, std::vector<int>>(end));

    return *end;
}

void __introsort_loop(std::__normal_iterator<int*, std::vector<int>> begin, 
                      std::__normal_iterator<int*, std::vector<int>> end, 
                      int threshold) {
    int* start = &(*begin);
    int* stop = &(*end);

    if (stop - start > 64) {
        int mid = start + ((stop - start) >> 2);

        __introsort_loop(begin, mid, threshold);
        __introsort_loop(mid, end, threshold);
    }

    // Insertion sort implementation
}

void __final_insertion_sort(std::__normal_iterator<int*, std::vector<int>> begin, 
                            std::__normal_iterator<int*, std::vector<int>> end) {
    int* start = &(*begin);
    int* stop = &(*end);

    if (stop - start > 64) {
        int* ptr = start + 1;

        while (ptr != stop) {
            int value = *ptr;
            int* it = ptr - 1;

            while (it >= start && *it > value) {
                *(it + 1) = *it;
                it--;
            }

            *(it + 1) = value;
            ptr++;
        }
    }

    // Insertion sort implementation
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
