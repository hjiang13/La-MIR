```cpp
#include <vector>
#include <stdexcept>

std::vector<int> factorize(int n) {
    std::vector<int> factors;
    int divisor = 2;
    while (divisor * divisor <= n) {
        if (n % divisor == 0) {
            n /= divisor;
            factors.push_back(divisor);
            divisor--;
        }
        divisor++;
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}
```