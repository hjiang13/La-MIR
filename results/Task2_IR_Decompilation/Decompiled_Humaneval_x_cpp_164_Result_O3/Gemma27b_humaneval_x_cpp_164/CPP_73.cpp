```c
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
```