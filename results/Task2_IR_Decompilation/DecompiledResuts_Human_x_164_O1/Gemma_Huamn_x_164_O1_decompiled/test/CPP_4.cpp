float mean_absolute_deviation(float* data, size_t size) {
  float sum = 0.0f;
  for (size_t i = 0; i < size; ++i) {
    sum += data[i];
  }
  float mean = sum / size;

  float absolute_sum = 0.0f;
  for (size_t i = 0; i < size; ++i) {
    absolute_sum += fabsf(data[i] - mean);
  }
  return absolute_sum / size;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}