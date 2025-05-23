```cpp
#include <iostream>
#include <string>
#include <cstdarg>

void rounded_avg(std::string& result, int a, int b) {
    if (a > b) {
        result = std::string(2, '\0');
        *((int16_t*)(result.data() + 2)) = 12589; 
        *((int64_t*)(result.data() + 8)) = 2; 
        result[10] = 0; 
    } else {
        std::string temp1, temp2;
        int sum = a + b;
        if (sum > 1) {
            int avg = sum / 2;
            char buffer[16];
            int length = snprintf(buffer, sizeof(buffer), "%d", avg);
            temp2 = std::string(buffer, length);
            result.append(temp2);
        }
    }
    result += '\0';
}

int main() {
    std::string output;
    rounded_avg(output, 5, 3);
    std::cout << output << std::endl;
    return 0;
}
```