```cpp
#include <vector>

bool below_zero(std::vector<int>& vec) {
  int* begin = &vec[0];
  int* end = &vec[1];
  int size = (end - begin) / 4;
  
  if (size > 1) {
    size = size > 0 ? size : 1;
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
      sum += vec[i];
      if (sum < 0) {
        return true;
      }
    }
  }
  
  return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_zero({}) == false);
    assert (below_zero({1, 2, -3, 1, 2, -3}) == false);
    assert (below_zero({1, 2, -4, 5, 6}) == true);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -4}) == false);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -5}) == true);
    assert (below_zero({1, -2, 2, -2, 5, -5, 4, -4}) == true);
}