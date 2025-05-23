```c++
#include <vector>

int can_arrange(std::vector<int> &vec) {
  int *begin = vec.data();
  int *end = vec.data() + vec.size();

  if (begin == end) {
    return -1;
  }

  int max_diff = (*end - *begin) / 4 + (*end - *begin) % 4;
  int min_diff = -1;

  for (int i = 0; i < max_diff; i++) {
    int diff = *(end - 1) - *(begin + i);
    if (min_diff == -1 || diff < min_diff) {
      min_diff = diff;
    }
  }

  return min_diff;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (can_arrange({1,2,4,3,5})==3);
    assert (can_arrange({1,2,4,5})==-1);
    assert (can_arrange({1,4,2,5,6,7,8,9,10})==2);
    assert (can_arrange({4,8,5,7,3})==4);
    assert (can_arrange({})==-1);
}
