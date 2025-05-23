```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

int search(std::vector<int, std::allocator<int>> vec) {
    std::vector<std::vector<int, std::allocator<int>>, std::allocator<std::vector<int, std::allocator<int>>>> nestedVec;
    int result = -1;
    int i = 0;

    while (i < vec.size()) {
        bool found = false;
        int j = 0;

        while (j < nestedVec.size()) {
            if (vec[i] == nestedVec[j][0]) {
                nestedVec[j][1]++;
                found = true;
                if (nestedVec[j][1] >= nestedVec[j][0]) {
                    if (nestedVec[j][0] > result) {
                        result = nestedVec[j][0];
                    }
                }
            }
            j++;
        }

        if (!found) {
            std::initializer_list<int> initList = {vec[i], 1};
            std::vector<int, std::allocator<int>> newVec(initList);
            nestedVec.push_back(std::move(newVec));
        }

        if (result == -1 && vec[i] == 1) {
            result = 1;
        }

        i++;
    }

    return result;
}
```