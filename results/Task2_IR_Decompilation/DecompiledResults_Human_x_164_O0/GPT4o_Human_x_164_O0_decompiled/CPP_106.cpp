```cpp
#include <vector>

void fi(std::vector<int>& vec, int val) {
    int size = 0;
    int capacity = 1;
    int index = 0;
    bool exceptionThrown = false;
    
    vec.clear();
    
    while (true) {
        if (size <= capacity) {
            if (index % 2 == 0) {
                vec.push_back(val);
            } else {
                vec.push_back(size);
            }
            size++;
            index++;
        } else {
            exceptionThrown = true;
            break;
        }
    }
    
    if (exceptionThrown) {
        vec.~vector();
    }
}
```