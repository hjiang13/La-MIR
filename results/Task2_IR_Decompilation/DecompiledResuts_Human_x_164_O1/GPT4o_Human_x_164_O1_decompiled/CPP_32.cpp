```cpp
#include <vector>
#include <cmath>
#include <stdexcept>

double poly(std::vector<double> const &vec, double x) {
    double result = 0.0;
    size_t n = vec.size();
    for (size_t i = 0; i < n; ++i) {
        result += vec[i] * pow(x, static_cast<double>(i));
    }
    return result;
}

double find_zero(std::vector<double> const &vec) {
    if (vec.empty()) {
        throw std::bad_alloc();
    }

    double *data = const_cast<double*>(vec.data());
    size_t n = vec.size();
    double result = 0.0;

    for (size_t i = 0; i < n; ++i) {
        result += data[i];
    }

    return fabs(result) > 1e-10 ? result : 0.0;
}
```