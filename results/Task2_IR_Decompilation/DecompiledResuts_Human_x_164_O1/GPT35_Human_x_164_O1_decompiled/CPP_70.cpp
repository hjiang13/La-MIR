```cpp
#include <vector>

void strange_sort_list(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    if (input.empty()) {
        return;
    }

    const int* begin = &input[0];
    const int* end = &input[input.size() - 1];

    if (begin == end) {
        result.push_back(*begin);
        return;
    }

    int step = (end - begin) / 4;
    int pivot = *(begin + 2 * step);

    std::vector<int> less, equal, greater;

    for (const int* it = begin; it <= end; ++it) {
        if (*it < pivot) {
            less.push_back(*it);
        } else if (*it == pivot) {
            equal.push_back(*it);
        } else {
            greater.push_back(*it);
        }
    }

    strange_sort_list(result, less);
    result.insert(result.end(), equal.begin(), equal.end());
    strange_sort_list(result, greater);
}

int main() {
    std::vector<int> input = {5, 3, 10, 2, 8, 7};
    std::vector<int> result;
    
    strange_sort_list(result, input);

    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
```