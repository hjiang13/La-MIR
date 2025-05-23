```cpp
#include <vector>
#include <cstdint>

extern "C" int64_t llvm_umax_i64(int64_t a, int64_t b);

int sum_squares(std::vector<int> &vec) {
    int64_t size = vec.size();
    if (size == 0) return 0;

    int64_t count = 0;
    int sum = 0;

    while (count < size) {
        if (count % 3 == 0) {
            int value = vec[count];
            sum += value * value;
        } else {
            int value = vec[count];
            if ((count & 3) == 0) {
                sum += value * value * value;
            } else {
                sum += value;
            }
        }
        count++;
    }

    return sum;
}
```