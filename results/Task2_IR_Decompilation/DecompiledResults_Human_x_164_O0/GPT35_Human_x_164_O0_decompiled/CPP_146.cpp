```cpp
#include <vector>
#include <string>

int specialFilter(std::vector<int>* vec) {
    int count = 0;
    for (int i = 0; i < vec->size(); i++) {
        if ((*vec)[i] > 10) {
            std::__cxx11::basic_string str = std::to_string((*vec)[i]);
            if (str.back() % 2 == 1) {
                count++;
            }
        }
    }
    return count;
}
```