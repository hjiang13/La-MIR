#include <stdio.h>
float max_element(float* begin, float* end) {
  float max = -10000.0f;
  while (begin != end) {
    if (*begin > max) {
      max = *begin;
    }
    begin++;
  }
  return max;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(max_element({1, 2, 3})- 3)<1e-4);
    assert (abs(max_element({5, 3, -5, 2, -3, 3, 9, 0, 124, 1, -10})- 124)<1e-4);
}
