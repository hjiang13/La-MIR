```cpp
#include <vector>
#include <iostream>
#include <algorithm>

void introsort_loop(int* begin, int* end, long size);
void final_insertion_sort(int* begin, int* end);

void strange_sort_list(std::vector<int>& vec) {
    std::vector<int> temp(vec.size());
    std::copy(vec.begin(), vec.end(), temp.begin());
    
    int* begin = temp.data();
    int* end = begin + vec.size();

    if (end - begin > 64) {
        introsort_loop(begin, end, end - begin);
    } else {
        final_insertion_sort(begin, end);
    }

    vec = std::move(temp);
}

void introsort_loop(int* begin, int* end, long size) {
    if (size <= 1) return;

    long mid = (size >> 1);
    std::nth_element(begin, begin + mid, end);

    introsort_loop(begin, begin + mid, mid);
    introsort_loop(begin + mid, end, size - mid);
}

void final_insertion_sort(int* begin, int* end) {
    for (int* i = begin + 1; i < end; ++i) {
        int value = *i;
        int* j = i - 1;

        while (j >= begin && *j > value) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = value;
    }
}
```