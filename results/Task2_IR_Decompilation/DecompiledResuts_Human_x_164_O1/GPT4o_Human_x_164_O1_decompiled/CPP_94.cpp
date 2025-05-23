```cpp
#include <vector>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

int skjkasdkd(std::vector<int>& vec) {
    std::string str1;
    std::string str2;
    int size = vec.size();
    
    if (size == 0) {
        return 0;
    }

    int result = 0;

    for (size_t i = 0; i < size; ++i) {
        int value = vec[i];
        if (value > 0) {
            if (value < 4) {
                result = value;
            } else {
                int divisor = 2;
                while (divisor * divisor <= value) {
                    if (value % divisor == 0) {
                        result = divisor;
                        break;
                    }
                    ++divisor;
                }
                if (result == 0) {
                    result = value;
                }
            }
        }
    }

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", result);
    str1 = buffer;

    return result;
}
```