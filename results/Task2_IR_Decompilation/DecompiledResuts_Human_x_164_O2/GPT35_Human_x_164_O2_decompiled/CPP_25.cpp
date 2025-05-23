```cpp
#include <vector>
#include <stdexcept>

void factorize(std::vector<int>& vec, int num) {
    if (num < 4) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    int div = 2;
    while (num % div != 0) {
        div++;
    }

    if (div == num) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    vec.push_back(div);
    num /= div;

    while (num > 1) {
        div = 2;
        while (num % div != 0) {
            div++;
        }

        vec.push_back(div);
        num /= div;
    }
}
```