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
