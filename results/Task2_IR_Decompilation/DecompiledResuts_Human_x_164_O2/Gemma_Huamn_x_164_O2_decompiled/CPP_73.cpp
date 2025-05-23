```c
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

```