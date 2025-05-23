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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (will_it_fly({3, 2, 3}, 9)==true);
    assert (will_it_fly({1, 2}, 5) == false);
    assert (will_it_fly({3}, 5) == true);
    assert (will_it_fly({3, 2, 3}, 1) == false);
    assert (will_it_fly({1, 2, 3}, 6) ==false);
    assert (will_it_fly({5}, 5) == true);
}
