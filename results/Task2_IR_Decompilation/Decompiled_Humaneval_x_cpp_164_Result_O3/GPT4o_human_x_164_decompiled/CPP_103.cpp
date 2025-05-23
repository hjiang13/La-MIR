```cpp
#include <string>
#include <cstdarg>
#include <cstring>

void rounded_avg(std::string &result, int a, int b) {
    if (a > b) {
        result = std::string(2, '\0');
        *(reinterpret_cast<uint64_t*>(&result) + 1) = 2;
        *(reinterpret_cast<uint16_t*>(&result) + 2) = 12589;
        result[2] = '\0';
    } else {
        std::string temp1;
        std::string temp2;
        int sum = a + b;

        if (sum > 1) {
            int avg = sum / 2;
            char buffer[16];
            int length = snprintf(buffer, sizeof(buffer), "%d", avg);
            temp2.append(buffer, length);
            result.append(temp2);
        } else {
            result.clear();
        }
    }
}

int main() {
    std::string result;
    rounded_avg(result, 5, 3);
    return 0;
}
```