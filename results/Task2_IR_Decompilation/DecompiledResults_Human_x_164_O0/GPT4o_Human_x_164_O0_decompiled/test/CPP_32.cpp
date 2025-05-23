#include <iostream>
#include <vector>
#include <cmath>

double poly(const std::vector<double>& vec, double x) {
    double result = 0.0;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i] * pow(x, static_cast<int>(i));
    }
    return result;
}

double find_zero(const std::vector<double>& coefficients) {
    double guess = 0.0;
    double tolerance = 1e-10;
    double f_value;
    int iteration = 0;
    int max_iterations = 1000;

    while (iteration < max_iterations) {
        f_value = poly(coefficients, guess);
        if (fabs(f_value) < tolerance) {
            return guess;
        }
        double derivative = poly(coefficients, guess + tolerance) - f_value;
        guess -= f_value / derivative;
        iteration++;
    }

    return guess;
}

int main() {
    std::vector<double> coefficients = {1.0, -3.0, 2.0}; // Example: x^2 - 3x + 2
    double root = find_zero(coefficients);
    std::cout << "Root: " << root << std::endl;
    return 0;
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
