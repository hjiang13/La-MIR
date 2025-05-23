```cpp
#include <vector>
#include <stdexcept>
#include <algorithm>

void unique_digits(std::vector<int>& vec, const std::vector<int>& input) {
    vec.clear();
    if (input.empty()) return;
    
    std::vector<int> temp(input);
    std::sort(temp.begin(), temp.end());
    auto last = std::unique(temp.begin(), temp.end());
    temp.erase(last, temp.end());
    
    for (const auto& elem : temp) {
        if (elem >= 0 && elem <= 9) {
            vec.push_back(elem);
        }
    }
}

int main() {
    std::vector<int> result;
    std::vector<int> input = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 0, 1};
    unique_digits(result, input);
    return 0;
}
```