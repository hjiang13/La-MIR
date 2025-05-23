```c
#include <vector>
#include <algorithm>

void remove_duplicates(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    std::vector<int>::const_iterator it = input.begin();
    while (it != input.end()) {
        if (std::find(result.begin(), result.end(), *it) == result.end()) {
            result.push_back(*it);
        }
        ++it;
    }
}

int main() {
    std::vector<int> input = {1, 2, 2, 3, 4, 4, 5};
    std::vector<int> result;
    remove_duplicates(result, input);
    return 0;
}
```