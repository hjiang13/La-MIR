```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

void strange_sort_list(std::vector<int>& result, const std::vector<int>& input) {
    std::vector<int> temp;
    temp.reserve(input.size());

    std::vector<int>::const_iterator begin = input.begin();
    std::vector<int>::const_iterator end = input.end();

    std::sort(begin, end);

    int i = 0;
    int j = input.size() - 1;

    while (i < j) {
        temp.push_back(input[i]);
        temp.push_back(input[j]);
        i++;
        j--;
    }

    if (i == j) {
        temp.push_back(input[i]);
    }

    result = std::move(temp);
}
```