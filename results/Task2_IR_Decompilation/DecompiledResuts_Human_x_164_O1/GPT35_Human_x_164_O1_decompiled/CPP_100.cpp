```c
#include <vector>

void make_a_pile(std::vector<int>& v, int size) {
    v.clear();
    v.reserve(size);

    for (int i = 0; i < size; i++) {
        v.push_back(i);
    }
}
```