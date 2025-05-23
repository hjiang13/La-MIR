#include <vector>

bool will_it_fly(const std::vector<int>& v, int x) {
  if (v.empty()) {
    return false;
  }
  
  size_t size = v.size();
  for (size_t i = 0; i < size / 2; ++i) {
    if (v[i] == v[size - i - 1]) {
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
