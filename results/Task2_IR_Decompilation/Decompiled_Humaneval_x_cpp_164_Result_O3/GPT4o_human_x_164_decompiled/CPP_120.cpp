```cpp
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

void maximum(std::vector<int>& result, const std::vector<int>& vec, int size) {
    if (size < 0) {
        throw std::length_error("cannot create std::vector larger than max_size()");
    }

    result.clear();
    result.resize(size);

    if (size == 0) {
        return;
    }

    std::vector<int> temp(vec.begin(), vec.end());
    std::make_heap(temp.begin(), temp.end());

    for (int i = 0; i < size; ++i) {
        std::pop_heap(temp.begin(), temp.end() - i);
        result[i] = temp[temp.size() - 1 - i];
    }
}

int main() {
    std::vector<int> vec = { 3, 1, 4, 1, 5, 9, 2, 6 };
    std::vector<int> result;
    maximum(result, vec, 5);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```