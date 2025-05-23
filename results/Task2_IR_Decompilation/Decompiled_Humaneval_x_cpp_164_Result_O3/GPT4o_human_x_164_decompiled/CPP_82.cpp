```cpp
#include <string>

bool prime_length(const std::string& str) {
    std::size_t length = str.size();
    
    if (length < 2) {
        return false;
    }
    
    if (length < 4) {
        return true;
    }
    
    int divisor = 2;
    while (true) {
        int remainder = length % divisor;
        bool isDivisible = (remainder == 0);
        divisor++;
        if (isDivisible) {
            return false;
        }
        
        int square = divisor * divisor;
        if (square > length) {
            return true;
        }
    }
}
```