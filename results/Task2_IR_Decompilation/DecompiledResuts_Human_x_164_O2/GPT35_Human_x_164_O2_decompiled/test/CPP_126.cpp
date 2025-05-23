```cpp
#include <vector>

bool is_sorted(std::vector<int> *vec) {
  int *data = vec->_M_impl._M_start;
  int *end = vec->_M_impl._M_finish;
  int *last = end - 1;
  int step = (end - data) / 2;
  
  if (step > 1) {
    int prev = *data;
    for (int i = 1; i < step; ++i) {
      int curr = data[i];
      if (curr < prev) {
        return false;
      }
      prev = curr;
    }
    
    int *mid = data + step;
    if (*mid < *data || *mid > *last) {
      return false;
    }
    
    for (int i = step + 1; i < end - 1; ++i) {
      int curr = data[i];
      if (curr < prev || curr > *last) {
        return false;
      }
      prev = curr;
    }
  }

  return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_sorted({5}) == true);
    assert (is_sorted({1, 2, 3, 4, 5}) == true);
    assert (is_sorted({1, 3, 2, 4, 5}) == false);
    assert (is_sorted({1, 2, 3, 4, 5, 6}) == true);
    assert (is_sorted({1, 2, 3, 4, 5, 6, 7}) == true);
    assert (is_sorted({1, 3, 2, 4, 5, 6, 7}) == false);
    assert (is_sorted({}) == true);
    assert (is_sorted({1}) == true);
    assert (is_sorted({3, 2, 1}) == false);
    assert (is_sorted({1, 2, 2, 2, 3, 4}) == false);
    assert (is_sorted({1, 2, 3, 3, 3, 4}) == false);
    assert (is_sorted({1, 2, 2, 3, 3, 4}) == true);
    assert (is_sorted({1, 2, 3, 4}) == true);
}
