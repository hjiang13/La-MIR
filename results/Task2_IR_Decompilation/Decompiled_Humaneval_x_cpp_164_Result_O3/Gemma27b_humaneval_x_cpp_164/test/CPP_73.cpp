int smallest_change(const std::vector<int>& vec) {
  int *end = vec._M_impl._M_data + vec.size();
  int *begin = vec._M_impl._M_data;
  int count = end - begin;
  int changes = 0;
  if (count == 0) {
    return 0;
  }
  for (int i = 0; i < count - 1; ++i) {
    if (begin[i] != begin[i + 1]) {
      ++changes;
    }
  }
  return changes;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (smallest_change({1,2,3,5,4,7,9,6}) == 4);
    assert (smallest_change({1, 2, 3, 4, 3, 2, 2}) == 1);
    assert (smallest_change({1, 4, 2}) == 1);
    assert (smallest_change({1, 4, 4, 2}) == 1);
    assert (smallest_change({1, 2, 3, 2, 1}) == 0);
    assert (smallest_change({3, 1, 1, 3}) == 0);
    assert (smallest_change({1}) == 0);
    assert (smallest_change({0, 1}) == 1);
}
