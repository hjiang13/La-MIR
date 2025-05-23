```cpp
#include <vector>
#include <iostream>
#include <cmath>

int sum_squares(std::vector<float> &vec) {
    float *begin = &vec[0];
    float *end = &vec[vec.size()];

    int sum = 0;
    for (float *ptr = begin; ptr < end; ptr++) {
        float value = std::ceil(*ptr);
        float square = value * value;
        sum += static_cast<int>(square);
    }

    return sum;
}

int main() {
    std::vector<float> vec = {1.5, 2.3, 3.7, 4.2, 5.6};
    int result = sum_squares(vec);
    std::cout << "Sum of squares: " << result << std::endl;

    return 0;
}
```