```c++
#include <vector>
#include <algorithm>

int count_nums(std::vector<int> &vec) {
    if (vec.empty()) {
        return 0;
    }

    int count = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        int num = std::abs(vec[i]);
        if (num > 9) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            count += sum;
        }
    }

    return count;
}
```