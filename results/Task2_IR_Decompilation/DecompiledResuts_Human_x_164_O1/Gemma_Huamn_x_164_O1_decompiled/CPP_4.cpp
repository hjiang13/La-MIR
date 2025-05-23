```c
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
```