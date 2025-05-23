```cpp
#include <vector>
#include <cmath>

long long double_the_difference(std::vector<float> &vec) {
    long long result = 0;
    int index = 0;

    while (true) {
        if (index >= vec.size()) {
            break;
        }
        
        float current = vec[index];
        float rounded = round(current);
        float difference = current - rounded;

        if (fabs(difference) < 1e-4) {
            index++;
            continue;
        }

        if (current > 0.0f) {
            float roundedCurrent = round(current);
            int intRoundedCurrent = static_cast<int>(roundedCurrent);
            int intCurrent = static_cast<int>(current);
            int product = intRoundedCurrent * intCurrent;
            result += product;
        }
        
        index++;
    }

    return result;
}
```