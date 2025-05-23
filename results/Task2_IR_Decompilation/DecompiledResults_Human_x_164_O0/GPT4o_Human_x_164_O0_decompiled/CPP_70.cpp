```cpp
#include <vector>
#include <algorithm>
#include <iostream>

void strange_sort_list(std::vector<int>& a, std::vector<int>& b) {
    std::vector<int> temp;
    for (auto it = b.begin(); it != b.end(); ++it) {
        temp.push_back(*it);
    }
    std::sort(temp.begin(), temp.end());
    
    for (size_t i = 0; i < temp.size(); ++i) {
        a.push_back(temp[i]);
    }
}

int main() {
    std::vector<int> a;
    std::vector<int> b = {5, 2, 9, 1, 5, 6};
    
    strange_sort_list(a, b);
    
    for (const int& val : a) {
        std::cout << val << " ";
    }
    
    return 0;
}
```