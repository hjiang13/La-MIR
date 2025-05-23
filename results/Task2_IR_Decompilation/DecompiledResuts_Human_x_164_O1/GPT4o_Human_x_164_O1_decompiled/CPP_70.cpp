```cpp
#include <vector>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

void introsort_loop(int* first, int* last, std::size_t depthLimit);
void final_insertion_sort(int* first, int* last);
void realloc_insert(std::vector<int>* vec, int* pos, int* value);

void strange_sort_list(std::vector<int>* result, const std::vector<int>* input) {
    result->clear();
    int* start = input->data();
    int* end = start + input->size();

    if (start == end) return;

    introsort_loop(start, end, (end - start) > 0 ? (end - start) : 1);
    for (int* it = start; it < end; ++it) {
        realloc_insert(result, it, it);
    }
}

void introsort_loop(int* first, int* last, std::size_t depthLimit) {
    if (last - first <= 64) {
        final_insertion_sort(first, last);
        return;
    }
    if (depthLimit == 0) {
        std::size_t n = last - first;
        std::qsort(first, n, sizeof(int), [](const void* a, const void* b) {
            return (*(int*)a - *(int*)b);
        });
        return;
    }
    depthLimit--;
    int* pivot = first + (last - first) / 2;
    std::iter_swap(pivot, last - 1);
    int* mid1 = std::partition(first, last - 1, [pivot](int value) {
        return value < *pivot;
    });
    std::iter_swap(mid1, last - 1);
    introsort_loop(first, mid1, depthLimit);
    introsort_loop(mid1 + 1, last, depthLimit);
}

void final_insertion_sort(int* first, int* last) {
    for (int* it = first + 1; it < last; ++it) {
        int value = *it;
        int* j = it - 1;
        while (j >= first && *j > value) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = value;
    }
}

void realloc_insert(std::vector<int>* vec, int* pos, int* value) {
    if (vec->size() + 1 > vec->capacity()) {
        vec->reserve(vec->size() + 1);
    }
    vec->insert(vec->begin() + (pos - vec->data()), *value);
}
```