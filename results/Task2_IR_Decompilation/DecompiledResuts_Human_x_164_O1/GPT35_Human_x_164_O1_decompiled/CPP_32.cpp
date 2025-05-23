```cpp
#include <vector>
#include <cmath>

double poly(std::vector<double>& input, double num) {
    double result = 0.0;

    for (int i = 0; i < input.size(); i++) {
        double val = input[i];
        double power = pow(num, static_cast<double>(i));
        result += val * power;
    }

    return result;
}

double find_zero(std::vector<double>& input) {
    double result = 0.0;

    for (int i = 0; i < input.size(); i++) {
        double val = input[i];
        double power = pow(0.0, static_cast<double>(i));
        result += val * power;
    }

    return result;
}
```