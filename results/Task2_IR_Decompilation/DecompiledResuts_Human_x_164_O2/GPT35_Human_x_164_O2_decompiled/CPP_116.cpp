```cpp
#include <vector>

void sort_array(std::vector<int> &output, std::vector<int> &input) {
    int* start = &input[0];
    int* end = &input[0];

    while (start != end) {
        int value = *start;
        int abs_value = abs(value);
        int count = 0;

        while (abs_value > 0) {
            count += abs_value & 1;
            abs_value >>= 1;
        }

        *end = count;
        end++;
        start++;
    }
}
```