```cpp
#include <vector>
#include <algorithm>

int solutions(std::vector<int> v) {
    int sum = 0;
    int size = v.size();

    for (int i = 0; i < size; i++) {
        int val = v[i];
        int remainder = val % 2;

        if (remainder == 1) {
            sum += val;
        }
    }

    return sum;
}
```