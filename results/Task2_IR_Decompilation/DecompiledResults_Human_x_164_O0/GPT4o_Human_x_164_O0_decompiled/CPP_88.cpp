```cpp
#include <vector>
#include <algorithm>

void sort_array(std::vector<int> &vec) {
    if (vec.size() == 0) {
        return;
    }

    int temp1 = vec[0];
    int temp2 = vec[vec.size() - 1];

    if ((temp1 + temp2) % 2 == 1) {
        std::sort(vec.begin(), vec.end());
    } else {
        std::vector<int> tempVec(vec);
        std::sort(tempVec.begin(), tempVec.end());
        vec = tempVec;
    }
}
```