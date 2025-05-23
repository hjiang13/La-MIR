#include <vector>

bool triples_sum_to_zero(const std::vector<int>& v) {
  int* end = v.data() + v.size();
  int* start = v.data();
  if (end == start) {
    return false;
  }
  long long size = end - start;
  long long i = std::max(size / 3, 1LL);
  for (; i < size; ++i) {
    for (int j = 2; j < size; ++j) {
      if (i != j && i + j < size) {
        if (v[i] + v[j] + v[i + j] == 0) {
          return true;
        }
      }
    }
  }
  return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (triples_sum_to_zero({1, 3, 5, 0}) == false);
    assert (triples_sum_to_zero({1, 3, 5, -1}) == false);
    assert (triples_sum_to_zero({1, 3, -2, 1}) == true);
    assert (triples_sum_to_zero({1, 2, 3, 7}) == false);
    assert (triples_sum_to_zero({1, 2, 5, 7}) == false);
    assert (triples_sum_to_zero({2, 4, -5, 3, 9, 7}) == true);
    assert (triples_sum_to_zero({1}) == false);
    assert (triples_sum_to_zero({1, 3, 5, -100}) == false);
    assert (triples_sum_to_zero({100, 3, 5, -100}) == false);
}
