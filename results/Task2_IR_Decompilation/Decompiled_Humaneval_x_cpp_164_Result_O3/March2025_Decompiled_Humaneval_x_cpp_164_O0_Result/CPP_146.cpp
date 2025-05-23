```cpp
#include <vector>
#include <string>
#include <stdexcept>

int specialFilter(std::vector<int> vec) {
    int count = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] > 10) {
            std::string str = std::to_string(vec[i]);
            if (str[0] % 2 == 1 && str[str.length() - 1] % 2 == 1) {
                ++count;
            }
        }
    }
    return count;
}
```