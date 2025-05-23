```c++
#include <vector>
#include <iostream>

void f(std::vector<int>& v, int n) {
    if (n < 1) {
        return;
    }

    int* first = nullptr;
    int* last = nullptr;
    int* end = nullptr;

    for (int i = 0; i < n; ++i) {
        int value = i * (i + 1);
        int* newLast = last + 1;

        if (newLast == end) {
            throw std::length_error("vector::_M_realloc_insert");
        }

        *last = value;
        last = newLast;
    }
}

int main() {
    std::vector<int> vec;
    f(vec, 10);

    for (int i : vec) {
        std::cout << i << " ";
    }

    return 0;
}
```