#include <iostream>
#include <vector>

using namespace std;

double poly(vector<double> &v, double x) {
  double result = 0;
  for (int i = 0; i < v.size(); i++) {
    result += v[i] * pow(x, i);
  }
  return result;
}

double find_zero(vector<double> &v) {
  double result = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 0) {
      result = i;
      break;
    }
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
