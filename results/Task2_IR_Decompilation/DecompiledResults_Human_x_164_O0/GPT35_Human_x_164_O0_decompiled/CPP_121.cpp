```cpp
#include <vector>

int solutions(std::vector<int> *v) {
    int sum = 0;
    for (int i = 0; i < v->size(); i++) {
        if ((*v)[i] % 2 == 1) {
            sum += (*v)[i];
        }
    }
    return sum;
}
```