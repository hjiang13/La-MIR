```cpp
#include <vector>
#include <iostream>
#include <stdexcept>

void realloc_insert(std::vector<int>& vec, int value) {
    if (vec.size() == 0) {
        vec.resize(1);
        vec[0] = value;
        return;
    }
    
    int size = vec.size();
    if (size < 2) {
        vec.push_back(value);
        return;
    }
    
    int newSize = size + 1;
    if (newSize > vec.capacity()) {
        vec.resize(newSize);
    }

    vec[size] = value;
}

int main() {
    std::vector<int> vec;
    realloc_insert(vec, 3);
    realloc_insert(vec, 5);
    realloc_insert(vec, 7);
    
    for (const auto& val : vec) {
        std::cout << val << std::endl;
    }
    
    return 0;
}
```