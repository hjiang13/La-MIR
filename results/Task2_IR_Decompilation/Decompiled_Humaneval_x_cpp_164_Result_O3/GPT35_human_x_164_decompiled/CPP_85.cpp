```c
#include <vector>

int add(std::vector<int> & vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}
```