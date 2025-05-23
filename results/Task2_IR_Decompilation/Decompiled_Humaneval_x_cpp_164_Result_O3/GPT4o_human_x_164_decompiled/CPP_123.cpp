```cpp
#include <vector>
#include <stdexcept>

void get_odd_collatz(std::vector<int>& vec, int n) {
    vec.clear();
    vec.reserve(4);
    vec.push_back(1);
    vec.push_back(1);
    
    if (n == 1) {
        return;
    }
    
    while (true) {
        int index = vec.size();
        int rem = n % 2;
        int div = n / 2;
        
        if (rem == 1) {
            vec.push_back(n);
            n = 3 * n + 1;
        } else {
            vec.push_back(n);
            n = div;
        }
        
        if (index >= vec.capacity()) {
            throw std::length_error("vector::_M_realloc_insert");
        }

        if (n == 1) {
            break;
        }
    }
}
```