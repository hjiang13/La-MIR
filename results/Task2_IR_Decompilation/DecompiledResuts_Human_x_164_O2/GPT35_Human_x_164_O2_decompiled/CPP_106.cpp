```cpp
#include <vector>
#include <stdexcept>

void f(std::vector<int>& v, int n) {
    if (n < 1) {
        return;
    }

    std::vector<int>::iterator it = v.begin();
    std::vector<int>::iterator end = v.end();

    if (end - it == 9223372036854775804) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    size_t size = n * (end - it);

    if (size > 2305843009213693951) {
        size = 2305843009213693951;
    }

    if (size == 0) {
        return;
    }

    std::vector<int> temp(size);
    std::copy(it, end, temp.begin());
    v = temp;
}
```