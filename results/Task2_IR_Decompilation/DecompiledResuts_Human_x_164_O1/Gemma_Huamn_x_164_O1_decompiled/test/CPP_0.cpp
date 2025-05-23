#include <stdlib.h>

float llvm_fabs_f32(float);
unsigned long long llvm_umax_i64(unsigned long long, unsigned long long);

int has_close_elements(float *v, unsigned long long n, float epsilon) {
  if (n == 0) return 0;

  unsigned long long i = 0;
  unsigned long long j = 1;
  while (j < n) {
    float diff = v[i] - v[j];
    if (llvm_fabs_f32(diff) < epsilon) return 1;
    i = j;
    j++;
  }
  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    vector<float> a={1.0, 2.0, 3.9, 4.0, 5.0, 2.2};
    assert (has_close_elements(a, 0.3)==true);
    assert (has_close_elements(a, 0.05) == false);

    assert (has_close_elements({1.0, 2.0, 5.9, 4.0, 5.0}, 0.95) == true);
    assert (has_close_elements({1.0, 2.0, 5.9, 4.0, 5.0}, 0.8) ==false);
    assert (has_close_elements({1.0, 2.0, 3.0, 4.0, 5.0}, 2.0) == true);
    assert (has_close_elements({1.1, 2.2, 3.1, 4.1, 5.1}, 1.0) == true);
    assert (has_close_elements({1.1, 2.2, 3.1, 4.1, 5.1}, 0.5) == false);
    
}
