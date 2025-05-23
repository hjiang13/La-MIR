```cpp
#include <vector>

int count_nums(std::vector<int> &vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > 0) {
            int num = vec[i];
            while (num < -9) {
                int digit = num % 10;
                sum += digit;
                num /= 10;
                if (num > 99) {
                    continue;
                }
            }
            if (sum > 0) {
                sum++;
            }
        }
    }
    return sum;
}
```