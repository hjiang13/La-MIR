```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

void unique_digits(std::vector<int>& result, const std::vector<int>& input) {
    int index = 0;
    bool isValid = false;
    
    while (index < input.size()) {
        int digit = input[index];
        isValid = true;
        
        if (digit % 2 == 0) {
            isValid = false;
        }
        
        if (isValid) {
            result.push_back(digit);
        }
        
        index++;
    }

    std::sort(result.begin(), result.end());
}
```