```cpp
#include <vector>

int smallest_change(std::vector<int> &vec) {
  int size = vec.size();
  int smallestChange = 0;

  for (int i = 0; i < size - 1; i++) {
    if (vec[i] != vec[i + 1]) {
      smallestChange++;
    }
  }

  return smallestChange;
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
