```cpp
#include <vector>
#include <algorithm>

void common(std::vector<int>& result, const std::vector<int>& vec1, const std::vector<int>& vec2) {
    result.clear();
    
    if (vec1.empty() || vec2.empty()) {
        return;
    }
    
    std::vector<int>::iterator it1 = vec1.begin();
    std::vector<int>::iterator it2 = vec2.begin();
    
    while (it1 != vec1.end() && it2 != vec2.end()) {
        if (*it1 < *it2) {
            result.push_back(*it1);
            ++it1;
        } else {
            result.push_back(*it2);
            ++it2;
        }
    }
    
    while (it1 != vec1.end()) {
        result.push_back(*it1);
        ++it1;
    }
    
    while (it2 != vec2.end()) {
        result.push_back(*it2);
        ++it2;
    }
}
```