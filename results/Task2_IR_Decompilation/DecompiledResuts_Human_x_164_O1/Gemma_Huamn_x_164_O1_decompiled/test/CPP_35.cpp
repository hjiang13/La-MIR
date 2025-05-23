#include <stdlib.h>

float max_element(float* begin, float* end) {
  if (begin == end) {
    return -1e4f;
  }
  float max_val = *begin;
  for (float* it = begin + 1; it != end; ++it) {
    if (*it > max_val) {
      max_val = *it;
    }
  }
  return max_val;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(max_element({1, 2, 3})- 3)<1e-4);
    assert (abs(max_element({5, 3, -5, 2, -3, 3, 9, 0, 124, 1, -10})- 124)<1e-4);
}
