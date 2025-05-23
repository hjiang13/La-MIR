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

#undef NDEBUG
#include<assert.h>
int main(){
   
    double solution;
    int ncoeff;
    for (int i=0;i<100;i++)
    {
        ncoeff = 2 * (1+rand()%4);
        vector<double> coeffs = {};
        for (int j=0;j<ncoeff;j++)
        {
            double coeff = -10+rand()%21;
            if (coeff == 0) coeff = 1;
            coeffs.push_back(coeff);
        }
        
        solution = find_zero(coeffs);
        assert (abs(poly(coeffs, solution))< 1e-3);
    }
}
