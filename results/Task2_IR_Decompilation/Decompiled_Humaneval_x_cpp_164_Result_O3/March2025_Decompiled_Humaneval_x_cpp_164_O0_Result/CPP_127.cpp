```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string intersection(std::vector<int> vec1, std::vector<int> vec2) {
    int max_val = std::max(vec1[0], vec2[0]);
    int min_val = std::min(vec1[1], vec2[1]);
    int diff = min_val - max_val;

    if (diff < 2) {
        return "NO";
    }

    for (int i = 2; i * i <= diff; ++i) {
        if (diff % i == 0) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    std::vector<int> vec1 = {1, 5};
    std::vector<int> vec2 = {2, 6};
    std::string result = intersection(vec1, vec2);
    std::cout << result << std::endl;
    return 0;
}
```