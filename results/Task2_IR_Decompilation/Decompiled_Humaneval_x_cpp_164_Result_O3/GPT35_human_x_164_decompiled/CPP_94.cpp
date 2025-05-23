```cpp
#include <vector>
#include <string>
#include <cstdio>

int skjkasdkd(std::vector<int>& vec) {
    int size = vec.size();
    if (size == 0) {
        return 0;
    }
    int maxVal = -1;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (vec[i] > maxVal) {
            maxVal = vec[i];
            count++;
        }
    }
    return count;
}
```