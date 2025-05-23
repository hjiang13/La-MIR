```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>

class Allocator {
public:
    Allocator() {}
    ~Allocator() {}
};

void make_a_pile(std::vector<int>& vec, int size) {
    Allocator allocator;
    int value = size;
    vec.push_back(value);
    for (int i = 1; i < size; ++i) {
        value = vec[i - 1] + 2;
        vec.push_back(value);
    }
}

int main() {
    std::vector<int> vec;
    make_a_pile(vec, 10);
    return 0;
}
```