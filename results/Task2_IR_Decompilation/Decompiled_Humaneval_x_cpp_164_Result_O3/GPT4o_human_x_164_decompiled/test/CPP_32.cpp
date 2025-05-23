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
