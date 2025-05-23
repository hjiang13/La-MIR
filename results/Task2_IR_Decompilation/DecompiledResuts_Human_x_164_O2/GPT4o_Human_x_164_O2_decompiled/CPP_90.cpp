```cpp
#include <vector>
#include <algorithm>

int next_smallest(std::vector<int>& vec) {
    int* start = vec.data();
    int* end = start + vec.size();
    
    if (start == end) return -1;

    int* current = start;
    int* next = end - 1;

    while (current < next) {
        if (current == next) {
            return *current;
        }
        int distance = (next - current) >> 2;
        int count_leading_zeros = __builtin_clzll(distance);
        int shift_value = (count_leading_zeros << 1) ^ 126;

        std::sort(current, next + 1);
        int smallest = *current;
        current++;

        // Find the next smallest element
        for (int i = 1; i < distance; i++) {
            if (*current < smallest) {
                smallest = *current;
            }
            current++;
        }
        return smallest;
    }
    return -1;
}

void introsort(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

void final_insertion_sort(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

int main() {
    std::vector<int> vec = {5, 3, 8, 1, 2};
    next_smallest(vec);
    introsort(vec);
    final_insertion_sort(vec);
    return 0;
}
```