#include <vector>

int solutions(const std::vector<int>& v) {
  const int* end = &v[0] + v.size();
  const int* begin = v.data();
  int sum = 0;
  if (end != begin) {
    long int half_size = (end - begin) / 2;
    long int max_iterations = std::max(half_size, 2L) - 1;
    for (long int i = 0; i <= max_iterations; ++i) {
      int val = begin[i * 2];
      if (val % 2 == 1) {
        sum += val;
      }
    }
  }
  return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (solutions({5, 8, 7, 1})    == 12);
    assert (solutions({3, 3, 3, 3, 3}) == 9);
    assert (solutions({30, 13, 24, 321}) == 0);
    assert (solutions({5, 9}) == 5);
    assert (solutions({2, 4, 8}) == 0);
    assert (solutions({30, 13, 23, 32}) == 23);
    assert (solutions({3, 13, 2, 9}) == 3);
}
