```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void pluck(std::vector<int>& out, const std::vector<int>& in) {
    out.clear();
    if (in.empty()) {
        return;
    }

    size_t size = in.size();
    for (size_t i = 0; i < size; ++i) {
        if (in[i] % 2 == 0) {
            out.push_back(in[i]);
        }
    }
}

void throw_length_error(const char* msg) {
    throw std::length_error(msg);
}
```