```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <limits>

void maximum(std::vector<int>& result, const std::vector<int>& input, int n) {
    std::vector<int> sorted_input = input;
    std::sort(sorted_input.begin(), sorted_input.end());
    if (n > sorted_input.size()) {
        throw std::length_error("cannot create std::vector larger than max_size()");
    }
    result = std::vector<int>(sorted_input.end() - n, sorted_input.end());
}
```