#include <vector>

bool will_it_fly(const std::vector<int>& v, int target) {
  if (v.empty()) {
    return false;
  }
  auto end = v.data() + v.size();
  auto size = end - v.data();
  if (size == 0) {
    return false;
  }
  
  for (size_t i = 0; i < ((size > 1) ? size : 1); ++i) {
    int val = v[i];
    int otherVal = v[size - i - 1];
    if (val == otherVal) {
      continue;
    }
    return false;
  }
  return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (will_it_fly({3, 2, 3}, 9)==true);
    assert (will_it_fly({1, 2}, 5) == false);
    assert (will_it_fly({3}, 5) == true);
    assert (will_it_fly({3, 2, 3}, 1) == false);
    assert (will_it_fly({1, 2, 3}, 6) ==false);
    assert (will_it_fly({5}, 5) == true);
}
