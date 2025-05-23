```cpp
#include <vector>
#include <iostream>

void count_up_to(std::vector<int>& vec, int n) {
    vec.clear();
    for (int i = 0; i < n; ++i) {
        vec.push_back(i);
    }
}

int main() {
    std::vector<int> vec;
    count_up_to(vec, 10);
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
```