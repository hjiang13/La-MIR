```cpp
#include <vector>
#include <algorithm>

void sort_array(std::vector<int>& result, std::vector<int>& input) {
    auto first = input.begin();
    auto last = input.end();
    
    if (first == last) {
        result.clear();
        return;
    }
    
    int len = std::distance(first, last);
    int mid = len / 2;
    int pivot = *std::next(first, mid);
    
    std::sort(first, last);
    std::inplace_merge(first, std::next(first, mid), last);
    
    result.assign(first, last);
}

int main() {
    std::vector<int> input = {5, 2, 8, 1, 9, 3};
    std::vector<int> result;
    
    sort_array(result, input);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    
    return 0;
}
```