```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

void maximum(std::vector<int>& result, const std::vector<int>& vec, int size) {
    if (size > vec.max_size()) {
        throw std::length_error("cannot create std::vector larger than max_size()");
    }
    
    std::vector<int> temp(vec.begin(), vec.end());
    std::sort(temp.begin(), temp.end());
    
    result = temp;
}

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    std::vector<int> result;
    
    try {
        maximum(result, vec, vec.size());
        
        for (int num : result) {
            std::cout << num << " ";
        }
    } catch (const std::length_error& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
```