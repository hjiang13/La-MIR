#include <math.h>

float mean_absolute_deviation(float* data, size_t size) {
  if (size == 0) {
    return 0.0f;
  }

  float sum = 0.0f;
  for (size_t i = 0; i < size; ++i) {
    sum += data[i];
  }
  float mean = sum / (float)size;

  float sum_abs_diff = 0.0f;
  for (size_t i = 0; i < size; ++i) {
    sum_abs_diff += fabsf(data[i] - mean);
  }

  return sum_abs_diff / (float)size;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}