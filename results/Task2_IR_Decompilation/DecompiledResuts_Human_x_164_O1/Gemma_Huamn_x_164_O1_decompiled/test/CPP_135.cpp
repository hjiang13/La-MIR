#include <stdint.h>

int can_arrange(int* begin, int* end) {
  if (begin == end) {
    return -1;
  }
  
  size_t size = (end - begin) / 2;
  if (size == 0) {
    return -1;
  }
  
  int max_index = -1;
  for (size_t i = 0; i < size; ++i) {
    if (i < begin[i]) {
      max_index = i;
    }
  }
  return max_index;
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
