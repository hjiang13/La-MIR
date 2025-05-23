```cpp
#include <vector>
#include <string>

std::string exchange(std::vector<int> vec1, std::vector<int> vec2) {
    int count = 0;
    for (int i = 0; i < vec1.size(); ++i) {
        if (vec1[i] % 2 == 0) {
            ++count;
        }
    }
    for (int i = 0; i < vec2.size(); ++i) {
        if (vec2[i] % 2 == 0) {
            ++count;
        }
    }
    return count >= vec1.size() ? "YES" : "NO";
}
```