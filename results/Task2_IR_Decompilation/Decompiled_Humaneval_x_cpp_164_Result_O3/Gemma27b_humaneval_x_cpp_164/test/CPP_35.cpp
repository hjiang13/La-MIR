#include <vector>

float max_element(const std::vector<float>& v) {
  float* end = v.data() + v.size();
  float* begin = v.data();
  if (begin == end) {
    return -10000.0f;
  }
  float max_val = -10000.0f;
  for (float* it = begin; it != end; ++it) {
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
