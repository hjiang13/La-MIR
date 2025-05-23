```cpp
#include <vector>
#include <algorithm>
#include <cmath>

extern "C" {
    long long double_the_difference(std::vector<float> &vec) {
        float* data = vec.data();
        float* end = data + vec.size();
        
        if (data == end) {
            return 0;
        }

        long long result = 0;
        long long size = end - data;

        for (long long i = 0; i < size; ++i) {
            float value = data[i];
            float rounded = roundf(value);
            float difference = value - rounded;
            double double_diff = static_cast<double>(difference);
            
            if (fabs(double_diff) < 1e-4 && value > 0.0f) {
                int rounded_int = static_cast<int>(rounded);
                int mod = rounded_int % 2;
                if (mod == 1) {
                    long long square = static_cast<long long>(rounded_int) * rounded_int;
                    result += square;
                }
            }
        }
        return result;
    }
}
```