```c
#include <vector>
#include <cmath>

double poly(std::vector<double> &vec, double val) {
    double result = 0.0;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i] * std::pow(val, static_cast<double>(i));
    }
    return result;
}

double find_zero(std::vector<double> &vec) {
    double result = 0.0;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i] * std::pow(0.0, static_cast<double>(i));
    }
    return result;
}
```