#include <stdint.h>

int is_sorted(int* arr, size_t size) {
  if (size <= 1) {
    return 1;
  }

  int prev = arr[0];
  for (size_t i = 1; i < size; ++i) {
    int current = arr[i];
    if (current < prev) {
      return 0;
    }
    
    if (current == prev && i > 1) {
      if (i + 1 < size && arr[i + 1] == prev) {
        continue;
      } else {
        return 0;
      }
    }
    prev = current;
  }
  return 1;
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
