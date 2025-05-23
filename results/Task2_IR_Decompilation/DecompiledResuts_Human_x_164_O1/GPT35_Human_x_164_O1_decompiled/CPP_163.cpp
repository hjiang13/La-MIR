```cpp
#include <vector>

void generate_integers(std::vector<int>& vec, int start, int end) {
    if (end < start) {
        int temp = start;
        start = end;
        end = temp;
    }

    std::memset(reinterpret_cast<void*>(&vec), 0, sizeof(vec));

    int* start_ptr = &vec[0];
    int* end_ptr = &vec[0] + 1;

    for (int i = start; i < end; ++i) {
        if (i < 10 && i % 2 == 0) {
            if (start_ptr == end_ptr) {
                *start_ptr = i;
            } else {
                *start_ptr = i;
                start_ptr++;
            }
        } else {
            vec.insert(start_ptr, i);
        }
    }
}
```