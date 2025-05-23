```c
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
```