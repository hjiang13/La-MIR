```cpp
#include <vector>
#include <cmath>
#include <stdexcept>

double poly(const std::vector<double>& coeffs, double x) {
    double result = 0.0;
    for (size_t i = 0; i < coeffs.size(); ++i) {
        result += coeffs[i] * std::pow(x, static_cast<int>(i));
    }
    return result;
}

double find_zero(const std::vector<double>& coeffs) {
    double x = 0.0;
    std::vector<double> temp(coeffs);
    double poly_val = poly(temp, x);

    while (std::abs(poly_val) > 1e-5) {
        double derivative = 0.0;
        for (size_t i = 1; i < coeffs.size(); ++i) {
            derivative += coeffs[i] * std::pow(x, static_cast<int>(i - 1)) * static_cast<double>(i);
        }
        x -= poly_val / derivative;
        temp = coeffs;
        poly_val = poly(temp, x);
    }

    return x;
}
```