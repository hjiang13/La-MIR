Here is the decompiled C++ source code:

```cpp
#include <vector>

int smallest_change(std::vector<int> &vec) {
    int *begin = &vec[0];
    int *end = &vec[1];
    long diff = (long)end - (long)begin;
    int size = (int)(diff >> 2) - 1;

    if (size == 0) {
        return 0;
    }

    int count = 0;
    long i = 0;
    long j = size;

    do {
        int val1 = *(begin + i);
        int val2 = *(begin + j);

        if (val1 != val2) {
            count++;
        }

        i++;
        j--;
    } while (size + j > i);

    return count;
}
```