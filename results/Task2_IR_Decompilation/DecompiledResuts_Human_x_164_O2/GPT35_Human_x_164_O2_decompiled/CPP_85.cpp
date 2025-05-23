```c
#include <vector>

int add(std::vector<int> v) {
    int sum = 0;
    
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    
    return sum;
}
```