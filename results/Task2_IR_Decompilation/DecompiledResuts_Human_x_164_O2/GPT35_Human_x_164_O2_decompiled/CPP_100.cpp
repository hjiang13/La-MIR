```c++
#include <vector>
#include <stdexcept>

void make_a_pile(std::vector<int>& v, int size) {
    v.clear();
    v.reserve(size);
    for (int i = 0; i < size; ++i) {
        v.push_back(i + 2);
    }
}

int main() {
    std::vector<int> v;
    make_a_pile(v, 10);

    return 0;
}
```