```cpp
#include <vector>
#include <cmath>

int count_nums(std::vector<int> &vec) {
    int count = 0;
    int index = 0;
    int temp = 0;
    int size = vec.size();

    while (index < size) {
        int value = vec[index];
        if (value > 0) {
            count++;
        } else {
            temp = std::abs(value);
            while (temp >= 10) {
                temp = temp / 10;
                count = count + temp % 10;
            }
            temp = count - temp;
            if (temp > 0) {
                count++;
            }
        }
        index++;
    }

    return count;
}
```