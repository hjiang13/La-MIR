float max_element(vector<float>* vec) {
  float* data = vec->data();
  float* end = data + vec->size();
  float max = -1.0e4;
  for (; data != end; ++data) {
    if (*data > max) {
      max = *data;
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
