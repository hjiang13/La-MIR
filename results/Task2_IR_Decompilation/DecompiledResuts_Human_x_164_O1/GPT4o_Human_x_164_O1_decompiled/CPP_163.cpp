```cpp
#include <vector>
#include <iostream>
#include <stdexcept>

void generate_integers(std::vector<int>& vec, int n, int m) {
    int start = std::min(n, m);
    int end = std::max(n, m);
    vec.clear();
    
    for (int i = start; i < end; ++i) {
        vec.push_back(i);
        if (vec.size() >= 10) {
            break;
        }
    }
}

int main() {
    std::vector<int> vec;
    generate_integers(vec, 5, 15);
    
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```