 #include <vector>

bool triples_sum_to_zero(std::vector<int>  v) {
  for (size_t i = 0; i < v.size(); ++i) {
    for (size_t j = i + 1; j < v.size(); ++j) {
      for (size_t k = j + 1; k < v.size(); ++k) {
        if (v[i] + v[j] + v[k] == 0) {
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
