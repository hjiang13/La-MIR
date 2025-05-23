```c
#include <vector>
#include <cmath>

double poly(std::vector<double> &v, double x) {
  double result = 0.0;
  for (int i = 0; i < v.size(); i++) {
    double pow_x = pow(x, i);
    result += v[i] * pow_x;
  }
  return result;
}

double find_zero(std::vector<double> &v) {
  double result = 0.0;
  for (int i = 0; i < v.size(); i++) {
    result += v[i];
  }
  return result;
}
```