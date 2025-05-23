```cpp
#include <vector>

int add(std::vector<int>& vec) {
    int sum = 0;
    int index = 0;

    while (true) {
        if (index >= vec.size()) {
            break;
        }
        int value = vec[index];
        if (value % 2 == 0) {
            sum += value;
        }
        index++;
    }

    return sum;
}
```