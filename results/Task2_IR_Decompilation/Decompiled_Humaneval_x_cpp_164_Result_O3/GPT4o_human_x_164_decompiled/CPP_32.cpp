```cpp
#include <vector>
#include <cmath>
#include <stdexcept>

double poly(const std::vector<double>& v, double x) {
    double result = 0.0;
    for (size_t i = 0; i < v.size(); ++i) {
        result += v[i] * pow(x, static_cast<double>(i));
    }
    return result;
}

double find_zero(const std::vector<double>& v) {
    if (v.empty()) {
        throw std::bad_alloc();
    }
    
    double result = 0.0;
    double step = 1e-5;  // Small step size for finding zero
    for (size_t i = 0; i < v.size(); ++i) {
        double value = poly(v, result);
        if (fabs(value) < 1e-6) {
            return result;
        }
        result += step;
    }
    
    return result; // Return the last calculated result if no zero was found
}
```