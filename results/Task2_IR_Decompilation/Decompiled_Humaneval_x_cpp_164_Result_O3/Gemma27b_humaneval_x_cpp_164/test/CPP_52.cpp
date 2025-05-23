#include <stdint.h>

int32_t below_threshold(int32_t* vec, int32_t threshold) {
  int32_t* end = vec + (sizeof(vec) / sizeof(vec[0]));
  int32_t size = end - vec;
  if (size == 0) {
    return 1;
  }
  int64_t max_index = size > 1 ? size : 1;
  if (vec[0] >= threshold) {
    return 0;
  }
  for (int64_t i = 1; i < max_index; ++i) {
    if (vec[i] >= threshold) {
      return 0;
    }
  }
  return 1;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_threshold({1, 2, 4, 10}, 100));
    assert (not(below_threshold({1, 20, 4, 10}, 5)));
    assert (below_threshold({1, 20, 4, 10}, 21));
    assert (below_threshold({1, 20, 4, 10}, 22));
    assert (below_threshold({1, 8, 4, 10}, 11));
    assert (not(below_threshold({1, 8, 4, 10}, 10)));
}
