```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>

void trii(std::vector<int>& vec, int n) {
    std::vector<int> temp;
    std::initializer_list<int> initList = { 1, 3 };
    temp = std::vector<int>(initList);

    if (n == 0) {
        vec.push_back(1);
        return;
    }

    for (int i = 0; i < n; ++i) {
        int count = i + 1;
        if (count % 2 == 0) {
            vec.push_back(count / 2);
        } else {
            int val1 = temp[count / 2];
            int val2 = temp[count / 2 - 1];
            vec.push_back(val1 + val2 + 1);
        }
    }
}
```