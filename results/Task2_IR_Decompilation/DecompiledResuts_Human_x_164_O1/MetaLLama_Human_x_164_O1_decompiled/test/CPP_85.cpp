#include <vector>

int add(std::vector<int> v) {
  int* begin = v._M_impl._M_start;
  int* end = v._M_impl._M_finish;
  int size = (end - begin) / 4;
  int sum = 0;
  if (size > 1) {
    int limit = (size - 2) / 2;
    for (int i = 0; i <= limit; i++) {
      int* ptr = begin + (i * 2 + 1);
      int val = *ptr;
      if ((val & 1) == 0) {
        sum += val;
      }
    }
  }
  return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (add({4, 88}) == 88);
    assert (add({4, 5, 6, 7, 2, 122}) == 122);
    assert (add({4, 0, 6, 7}) == 0);
    assert (add({4, 4, 6, 8}) == 12);
}
