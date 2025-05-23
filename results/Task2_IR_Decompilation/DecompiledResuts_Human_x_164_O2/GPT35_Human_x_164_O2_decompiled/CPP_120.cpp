```c++
#include <vector>
#include <iostream>

void maximum(std::vector<int>& result, const std::vector<int>& input, int size) {
    int* begin = &input[0];
    int* end = &input[input.size()];
    
    int* max_size = begin + size;
    
    if (begin == end) {
        return;
    }
    
    std::sort(begin, end);
    
    result.resize(size);
    
    std::copy(begin, max_size, result.begin());
}

int main() {
    std::vector<int> input = {9, 2, 5, 8, 3, 7, 1, 6, 4};
    std::vector<int> result;
    
    int max_size = 5;
    
    maximum(result, input, max_size);
    
    for (int i : result) {
        std::cout << i << " ";
    }
    
    return 0;
}
```