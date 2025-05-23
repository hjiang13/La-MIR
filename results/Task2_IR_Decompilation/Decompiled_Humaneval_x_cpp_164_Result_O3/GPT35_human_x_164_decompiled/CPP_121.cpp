```cpp
#include <vector>

int solutions(std::vector<int> &vec) {
    int *data = vec.data();
    int size = vec.size();

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value = data[i];
        if (value % 2 == 1) {
            sum += value;
        }
    }

    return sum;
}
```