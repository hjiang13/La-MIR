```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

void sort_array(std::vector<int>& result, const std::vector<int>& input) {
    if (input.size() == 0) {
        result = std::vector<int>();
        return;
    }

    int first = input[0];
    int last = input[input.size() - 1];
    int sum = first + last;
    bool isOdd = (sum % 2 == 1);

    if (isOdd) {
        std::vector<int> temp(input.begin(), input.end());
        std::sort(temp.begin(), temp.end());
        result = std::move(temp);
    } else {
        std::vector<int> temp;
        for (int i = input.size() - 1; i >= 0; --i) {
            temp.push_back(input[i]);
        }
        result = std::move(temp);
    }
}
```