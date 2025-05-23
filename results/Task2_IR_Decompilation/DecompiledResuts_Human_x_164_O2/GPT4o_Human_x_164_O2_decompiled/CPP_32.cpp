```cpp
#include <vector>
#include <cmath>
#include <stdexcept>
#include <cstdlib>

double poly(const std::vector<double>& vec, double x) {
    double result = 0.0;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i] * pow(x, static_cast<double>(i));
    }
    return result;
}

double find_zero(const std::vector<double>& vec) {
    if (vec.empty()) {
        throw std::bad_alloc();
    }

    double tolerance = 1e-10;
    double guess = 0.0;
    double value = poly(vec, guess);
    
    while (fabs(value) > tolerance) {
        guess += value < 0 ? -0.1 : 0.1; 
        value = poly(vec, guess);
    }
    return guess;
}
```