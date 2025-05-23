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
