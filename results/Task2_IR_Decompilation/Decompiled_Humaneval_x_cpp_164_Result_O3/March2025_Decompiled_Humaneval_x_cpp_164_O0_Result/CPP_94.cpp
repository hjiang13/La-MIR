```cpp
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

int skjkasdkdSt6vectorIiSaIiEE(std::vector<int>& vec) {
    int result = 0;
    int max_value = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] > max_value) {
            bool flag = true;
            int multiplier = 2;
            while (true) {
                int product = multiplier * multiplier;
                if (product <= vec[i]) {
                    if (vec[i] % multiplier == 0) {
                        flag = false;
                        break;
                    }
                    ++multiplier;
                } else {
                    break;
                }
            }
            if (flag) {
                max_value = vec[i];
            }
        }
    }
    std::string str = std::to_string(max_value);
    int sum = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        sum += str[i] - '0';
    }
    return sum;
}
```