```cpp
#include <vector>

int solutions(std::vector<int> vec) {
    int result = 0;
    int index = 0;

    while (index * 2 < vec.size()) {
        if (vec[index * 2] % 2 == 1) {
            result += vec[index * 2];
        }
        index++;
    }

    return result;
}
```