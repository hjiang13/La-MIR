```cpp
#include <vector>

bool will_it_fly(std::vector<int> &vec, int size) {
    int* begin = &vec[0];
    int* end = &vec[size];
    
    int diff = end - begin;
    int step = diff / 4;
    
    if (diff == 0) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        int current = begin[i];
        int next = begin[(i + step) % size];
        
        if (current != next) {
            return false;
        }
    }

    return true;
}
```
```cpp
#include <vector>

bool will_it_fly(std::vector<int> &vec, int size) {
    int* begin = &vec[0];
    int* end = &vec[size];
    
    int diff = end - begin;
    int step = diff / 4;
    
    if (diff == 0) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        int current = begin[i];
        int next = begin[(i + step) % size];
        
        if (current != next) {
            return false;
        }
    }

    return true;
}
```