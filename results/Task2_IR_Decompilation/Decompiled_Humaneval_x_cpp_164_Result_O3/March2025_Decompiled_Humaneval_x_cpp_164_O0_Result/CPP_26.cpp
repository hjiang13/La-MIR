```cpp
#include <vector>
#include <algorithm>
#include <iterator>

void remove_duplicates(std::vector<int>& result, const std::vector<int>& input) {
    std::vector<int> temp1;
    std::vector<int> temp2;

    for (size_t i = 0; i < input.size(); ++i) {
        if (std::find(temp1.begin(), temp1.end(), input[i]) == temp1.end()) {
            if (std::find(temp2.begin(), temp2.end(), input[i]) == temp2.end()) {
                temp2.push_back(input[i]);
            } else {
                temp1.push_back(input[i]);
            }
        }
    }

    for (size_t i = 0; i < input.size(); ++i) {
        if (std::find(temp2.begin(), temp2.end(), input[i]) == temp2.end()) {
            result.push_back(input[i]);
        }
    }
}
```