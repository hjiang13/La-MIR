#include <vector>
#include <algorithm>

int next_smallest(std::vector<int>& vec) {
    int* first = vec.data();
    int* last = vec.data() + vec.size();

    if (first == last) return -1;

    int* end = last - 1;
    if (first == end) return *first;

    // Main logic
    std::iter_swap(end, std::min_element(first, end));
    std::sort(first, end);
    
    return *end;
}

void introsort(int* start, int* end, long size) {
    if (size < 64) {
        std::sort(start, end);
    } else {
        long mid = size / 2;
        introsort(start, start + mid, mid);
        introsort(start + mid, end, size - mid);
    }
}

void final_insertion_sort(int* start, int* end) {
    if (start == end) return;

    for (int* i = start + 1; i < end; ++i) {
        int key = *i;
        int* j = i - 1;
        while (j >= start && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

// Main entry point for demonstration
int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    int smallest = next_smallest(vec);
    return smallest;
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
