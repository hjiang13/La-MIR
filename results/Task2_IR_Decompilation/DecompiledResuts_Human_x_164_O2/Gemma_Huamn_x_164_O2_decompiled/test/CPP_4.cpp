#include <math.h>

float mean_absolute_deviation(float *arr, size_t n) {
  float sum = 0.0f;
  for (size_t i = 0; i < n; ++i) {
    sum += arr[i];
  }
  float mean = sum / n;

  float mad = 0.0f;
  for (size_t i = 0; i < n; ++i) {
    mad += fabsf(arr[i] - mean);
  }
  return mad / n;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}