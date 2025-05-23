#include <stdlib.h>
#include <string.h>
#include <math.h>

double poly(double *v, double x, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += v[i] * pow(x, i);
    }
    return sum;
}

double find_zero(double *v, int n) {
    double *coeffs = (double *)malloc(n * sizeof(double));
    if (coeffs == NULL) {
        exit(1);
    }
    memcpy(coeffs, v, n * sizeof(double));

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += coeffs[i] * pow(0.0, i);
    }
    free(coeffs);

    if (fabs(sum) > 1e-6) {
        double x = 0.0;
        double y = 0.0;
        double *tmp = (double *)malloc(n * sizeof(double));
        if (tmp == NULL) {
            exit(1);
        }
        while (1) {
            double *new_coeffs = (double *)malloc(n * sizeof(double));
            if (new_coeffs == NULL) {
                exit(1);
            }
            memcpy(new_coeffs, v, n * sizeof(double));
            double new_sum = 0.0;
            for (int i = 0; i < n; i++) {
                new_sum += new_coeffs[i] * pow(x, i);
            }
            free(new_coeffs);
            if (fabs(new_sum) <= 1e-6) {
                break;
            }
            double z = 0.0;
            for (int i = 1; i < n; i++) {
                z += v[i] * pow(y, i - 1) * i;
            }
            x = y;
            y = x - new_sum / z;
        }
        free(tmp);
        return x;
    } else {
        return 0.0;
    }
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
