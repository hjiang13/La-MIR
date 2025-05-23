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
