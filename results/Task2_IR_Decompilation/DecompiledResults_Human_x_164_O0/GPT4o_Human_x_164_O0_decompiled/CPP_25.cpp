```cpp
#include <vector>
#include <iostream>

void factorize(std::vector<int>& vec, int n) {
    vec.clear();
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            vec.push_back(i);
        }
    }
}

int main() {
    std::vector<int> factors;
    int number = 12; // Example number
    factorize(factors, number);
    
    for (int factor : factors) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;

    return 0;
}
```