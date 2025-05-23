```cpp
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>

int do_algebra(std::vector<std::string> &vec1, std::vector<std::string> &vec2) {
    std::vector<int> result;
    int count = 0;

    for (size_t i = 0; i < vec1.size(); ++i) {
        for (size_t j = 0; j < vec2.size(); ++j) {
            if (vec1[i] == vec2[j]) {
                result.push_back(count);
            } else {
                count++;
            }
        }
    }
    
    return result.size();
}

int main() {
    std::vector<std::string> vec1 = {"**", "*", "//", "+", "-"};
    std::vector<std::string> vec2 = {"**", "*", "//", "+", "-"};

    int result = do_algebra(vec1, vec2);
    
    return result;
}
```