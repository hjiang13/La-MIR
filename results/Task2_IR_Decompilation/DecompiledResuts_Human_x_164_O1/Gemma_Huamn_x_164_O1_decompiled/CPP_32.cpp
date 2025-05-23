```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double _Z4polySt6vectorIdSaIdEEd(double* const vector, size_t size, double x) {
  double result = 0.0;
  for (size_t i = 0; i < size; ++i) {
    result += vector[i] * pow(x, i);
  }
  return result;
}

double _Z9find_zeroSt6vectorIdSaIdEE(double* const vector, size_t size) {
  double* new_vector = 0;
  double result = 0.0;

  new_vector = (double*)malloc(size * sizeof(double));
  if (new_vector == NULL) {
    exit(1);
  }
  for (size_t i = 0; i < size; ++i) {
    new_vector[i] = vector[i];
    result += new_vector[i] * pow(0.0, i);
  }

  free(new_vector);
  if (fabs(result) > 1.0e+10) {
    double previous_result = result;
    result = 0.0;
    for (size_t i = 1; i <= size; ++i) {
      result += new_vector[i - 1] * pow(previous_result, i - 1);
    }
    if (fabs(result) > 1.0e+10) {
      return result;
    }
  }
  return result;
}

int main() {
  double* vector = (double*)malloc(sizeof(double) * 3);
  vector[0] = 1.0;
  vector[1] = 2.0;
  vector[2] = 3.0;
  double result = _Z9find_zeroSt6vectorIdSaIdEE(vector, 3);
  printf("Result: %f\n", result);
  free(vector);
  return 0;
}```