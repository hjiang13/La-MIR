```cpp
#include <vector>
#include <algorithm>

template<typename T>
long double double_the_difference(std::vector<T> &vec) {
    if (vec.size() == 0) {
        return 0;
    }

    long long max_diff = 1;
    long long sum = 0;

    for (int i = 0; i < vec.size(); i++) {
        T val = vec[i];
        T rounded_val = std::round(val);
        double diff = val - rounded_val;

        if (diff < 1.000000e-04 && val > 0.000000e+00) {
            int rounded_int = static_cast<int>(rounded_val);
            if (rounded_int % 2 == 1) {
                sum += static_cast<long long>(rounded_int * rounded_int);
            }
        }
    }

    return sum;
}
```