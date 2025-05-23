float max_element(vector<float> &v) {
  float *begin = v.begin();
  float *end = v.end();
  float max = -1.0e+04;
  for (float *p = begin; p != end; p++) {
    if (*p > max) {
      max = *p;
    }
  }
  return max;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(max_element({1, 2, 3})- 3)<1e-4);
    assert (abs(max_element({5, 3, -5, 2, -3, 3, 9, 0, 124, 1, -10})- 124)<1e-4);
}
