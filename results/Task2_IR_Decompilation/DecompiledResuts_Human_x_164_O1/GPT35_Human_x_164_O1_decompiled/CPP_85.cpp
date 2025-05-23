```c++
#include <vector>

int add(std::vector<int> vec) {
    int* first = vec._M_impl._M_start._M_p;
    int* last = vec._M_impl._M_finish._M_p;

    int size = (last - first) >> 2;
    if (size > 1) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            int value = *(first + i);
            if (value & 1 == 0) {
                sum += value;
            }
        }
        return sum;
    }

    return 0;
}
```