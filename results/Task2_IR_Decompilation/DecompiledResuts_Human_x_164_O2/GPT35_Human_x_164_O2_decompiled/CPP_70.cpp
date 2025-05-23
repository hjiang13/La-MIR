```cpp
#include <vector>
#include <algorithm>

std::vector<int> strange_sort_list(std::vector<int>& input) {
    std::vector<int> result(input.size());

    if (input.empty()) {
        return result;
    }

    std::copy(input.begin(), input.end(), result.begin());

    std::sort(result.begin(), result.end(), [](int a, int b) {
        return a < b;
    });

    return result;
}

int main() {
    std::vector<int> input = {4, 2, 7, 1, 5};
    std::vector<int> output = strange_sort_list(input);

    return 0;
}
```