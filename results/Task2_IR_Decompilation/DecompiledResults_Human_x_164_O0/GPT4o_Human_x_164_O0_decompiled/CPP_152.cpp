```cpp
#include <vector>
#include <cstdlib>
#include <cmath>

void compare(std::vector<int>& v1, std::vector<int>& v2, std::vector<int>& result) {
    result.clear();
    for (size_t i = 0; i < v1.size(); ++i) {
        if (i < v2.size()) {
            int diff = std::abs(v1[i] - v2[i]);
            result.push_back(diff);
        }
    }
}

int main() {
    std::vector<int> vector1 = {1, 2, 3, 4};
    std::vector<int> vector2 = {4, 3, 2, 1};
    std::vector<int> result;

    compare(vector1, vector2, result);
    
    for (int val : result) {
        std::cout << val << " ";
    }
    
    return 0;
}
```