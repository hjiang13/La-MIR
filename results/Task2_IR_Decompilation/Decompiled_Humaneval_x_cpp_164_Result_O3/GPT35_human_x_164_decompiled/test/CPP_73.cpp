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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (smallest_change({1,2,3,5,4,7,9,6}) == 4);
    assert (smallest_change({1, 2, 3, 4, 3, 2, 2}) == 1);
    assert (smallest_change({1, 4, 2}) == 1);
    assert (smallest_change({1, 4, 4, 2}) == 1);
    assert (smallest_change({1, 2, 3, 2, 1}) == 0);
    assert (smallest_change({3, 1, 1, 3}) == 0);
    assert (smallest_change({1}) == 0);
    assert (smallest_change({0, 1}) == 1);
}
