```cpp
#include <vector>
#include <algorithm>

float median(std::vector<float> vec) {
    if (vec.size() == 0) {
        return 0;
    }

    std::sort(vec.begin(), vec.end());

    int middle = vec.size() / 2;
    float median_value = 0;

    if (vec.size() % 2 == 0) {
        median_value = (vec[middle - 1] + vec[middle]) / 2.0;
    } else {
        median_value = vec[middle];
    }

    return median_value;
}

int main() {
    std::vector<float> numbers = {1.0, 2.0, 3.0, 4.0, 5.0};
    float result = median(numbers);

    return 0;
}
```