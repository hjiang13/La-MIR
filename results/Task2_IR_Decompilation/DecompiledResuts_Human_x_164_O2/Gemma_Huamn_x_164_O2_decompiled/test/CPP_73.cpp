#include <vector>

int smallest_change(std::vector<int> const& v) {
  auto last = v.data() + v.size();
  auto first = v.data();
  auto diff = last - first;
  auto len = diff / sizeof(int);
  auto count = len - 1;
  if (count == 0)
    return 0;
  int result = 0;
  for (auto i = 0; i < count; ++i) {
    if (first[i] != first[i + 1])
      ++result;
  }
  return result;
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
