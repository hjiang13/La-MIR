```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

void pluck(std::vector<int>& vec1, const std::vector<int>& vec2) {
    int* ptr1 = vec1.data();
    int* ptr2 = vec2.data();
    
    if (ptr1 == ptr2) {
        return;
    }

    size_t index = 0;
    while (index < vec1.size()) {
        int value = ptr1[index];
        if ((value & 1) == 0) {
            if (index < vec2.size()) {
                vec1.push_back(value);
            }
        }
        index++;
    }
}

int main() {
    std::vector<int> vec1;
    std::vector<int> vec2 = {1, 2, 3, 4, 5};

    pluck(vec1, vec2);
    
    for (int val : vec1) {
        std::cout << val << std::endl;
    }

    return 0;
}
```