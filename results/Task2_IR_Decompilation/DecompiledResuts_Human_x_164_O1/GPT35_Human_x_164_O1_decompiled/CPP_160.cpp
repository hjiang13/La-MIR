```cpp
#include <vector>
#include <string>
#include <cmath>

void do_algebra(std::vector<std::string>& vec1, std::vector<int>& vec2) {
    std::vector<int>::iterator it1 = vec2.begin();
    std::vector<int>::iterator it2 = vec2.begin();
    
    for (; it1 != vec2.end(); ++it1) {
        int val = *it1;
        int index = std::distance(vec2.begin(), it1);
        
        if (index < vec1.size()) {
            std::string str = vec1[index];
            if (str == "**") {
                int val2 = *(it2 + 1);
                double result = pow(val, val2);
                *it2 = static_cast<int>(result);
            }
        }
        
        it2++;
    }
}
```