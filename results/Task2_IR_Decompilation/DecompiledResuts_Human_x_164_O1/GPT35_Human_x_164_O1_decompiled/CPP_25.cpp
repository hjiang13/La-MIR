```cpp
#include <vector>

void factorize(std::vector<int>& result, int num) {
    result.clear();
    
    if (num < 4) {
        result.push_back(num);
        return;
    }
    
    int divisor = 2;
    while (num % divisor != 0) {
        divisor++;
    }
    
    result.push_back(divisor);
    factorize(result, num / divisor);
}

int main() {
    std::vector<int> result;
    factorize(result, 100); // Change the number here for factorization
    return 0;
}
```