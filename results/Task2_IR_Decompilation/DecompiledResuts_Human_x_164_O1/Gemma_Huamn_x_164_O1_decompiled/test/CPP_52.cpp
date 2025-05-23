#include <vector>

bool below_threshold(const std::vector<int>& v, int threshold) {
  if (v.empty()) {
    return false;
  }
  size_t size = v.size();
  if (size == 0) {
    return false;
  }
  for (size_t i = 0; i < size; ++i) {
    if (v[i] < threshold) {
      return true;
    }
  }
  return false;
}
```
<|im_end|>
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
