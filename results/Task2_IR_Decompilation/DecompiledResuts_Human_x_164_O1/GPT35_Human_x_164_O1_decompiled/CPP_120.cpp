```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

void maximum(std::vector<int>& result, const std::vector<int>& input, int size) {
    if (input.data() == nullptr) {
        throw std::length_error("cannot create std::vector larger than max_size()");
    }

    if (size < 0) {
        throw std::length_error("cannot create std::vector with negative size");
    }

    result.resize(size);

    if (size == 0) {
        return;
    }

    std::copy(input.begin(), input.end(), result.begin());
    std::sort(result.rbegin(), result.rend());
}

int main() {
    std::vector<int> input = {1, 5, 3, 7, 2};
    std::vector<int> result;

    maximum(result, input, 3);

    for (int i : result) {
        std::cout << i << " ";
    }

    return 0;
}
```